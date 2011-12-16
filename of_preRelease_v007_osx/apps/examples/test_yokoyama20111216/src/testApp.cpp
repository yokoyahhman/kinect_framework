#include "testApp.h"


// 円の情報、これらはスペースキーが押されたときに追加される
int circleCount = 0;
vector <ofPoint *> speeds;
vector <ofPoint *> locs;
vector <ofColor *> colors;

// 最初に一回だけ呼び出される関数
//---画面やデバイスの初期化を行う-----------------------------------------------------------
void testApp::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE);
	ofLog(OF_LOG_VERBOSE, "Start setup dao");

	// 画面の設定
    ofSetFrameRate(60);
	ofSetCircleResolution(128);
	ofBackground(255, 255, 255);
	ofSetWindowShape(300, 300);
	ofEnableSmoothing();
	
	// 最初の円を一つ作る
	speeds.push_back(new ofPoint(3, 4));
	locs.push_back(new ofPoint(100, 100));
	ofColor *color = new ofColor();
	color->r = 0;
	colors.push_back(color);
	circleCount++;
}

// 毎フレーム呼び出される関数
//--------------------------------------------------------------
void testApp::update(){
    // 各円の座標の更新を行う
	for (int i = 0; i< circleCount; i++) {
	    ofPoint *loc = locs[i];
		ofPoint *speed = speeds[i];
		int locX = loc->x + speed->x;
		int locY = loc->y + speed->y;
		
		loc->set(locX, locY);
		
		// 画面端まできていたら進行方向を反転させる
		if (locX < 0 || locX > ofGetWidth()) {
			speed->set(speed->x * -1, speed->y);
		}
		if (locY < 0 || locY > ofGetHeight()) {
		    speed->set(speed->x, speed->y * -1);
		}
	}
}

// 毎フレームupdate関数の後に呼び出される関数
//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(255);
	// 各円の描画
	for (int i = 0; i < circleCount; i++) {
	    ofPoint *pos = locs[i];
		ofColor *color = colors[i];
		ofSetColor(color->r, color->g, color->b);
		ofCircle(pos->x, pos->y, 20);
	}
}

// キーが押されたときに呼び出される関数
void testApp::keyPressed(int key) {
	switch (key) {
	    // スペースキーが押されたとき
		case ' ':
			// ランダムの座標と移動速度と色を新たな円として追加する
			ofPoint *speed = new ofPoint(ofRandom(-5, 5),
										 ofRandom(-5, 5));
			ofPoint *loc = new ofPoint(ofRandom(0, 300),
										 ofRandom(0, 300));
			ofColor *color = new ofColor();
			color->r = ofRandom(0, 255);
			color->g = ofRandom(0, 255);
			color->b = ofRandom(0, 255);
			colors.push_back(color);
			speeds.push_back(speed);
			locs.push_back(loc);
			circleCount++;
			break;
	
	}
}


//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}
//
////--------------------------------------------------------------
//void testApp::gotMessage(ofMessage msg){
//
//}
//
////--------------------------------------------------------------
//void testApp::dragEvent(ofDragInfo info){
//	
//	if( info.files.size() > 0 ){
//		dragPt = info.position;
//		
//		draggedImages.assign( info.files.size(), ofImage() );
//		for(int k = 0; k < info.files.size(); k++){
//			draggedImages[k].loadImage(info.files[k]);
//		}
//	}
//
//}

