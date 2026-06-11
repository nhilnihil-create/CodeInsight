#include<iostream>
#include<cstring>
using namespace std;

const int MAX = 8000;
const char FORWARD = 'F';
const char TURN = 'T';

int main() {
	string s;
	int x, y;
	cin >> s >> x >> y;
	
	int read = 0;
	for (;s[read] == FORWARD;++ read) -- x; // 最初の文字数だけxを減らす
	x = x < 0 ? -x : x;
	y = y < 0 ? -y : y;
	
	int xGo[MAX], yGo[MAX], xp = 0, yp = 0; // 部分和問題に必要な値
	memset(xGo, 0, sizeof(int) * MAX);
	memset(yGo, 0, sizeof(int) * MAX);
	
	for (++ read;s[read] != '\0';++ read) {
		for (;s[read] == FORWARD;++ read) { // y軸方向
			++ yGo[yp];
		}
		++ yp;
		if (s[read] == '\0') break;
		for (++ read;s[read] == FORWARD;++ read) { // x軸方向
			++ xGo[xp];
		}
		++ xp;
	}
	
	bool dpX[MAX], dpY[MAX]; // 部分和問題はdpで解けるよ
	int xSum = 0, ySum = 0;
	memset(dpX, false, sizeof(bool) * MAX);
	dpX[0] = true;
	for (int i = 0;i < xp;++ i) {
		int add = xGo[i];
		xSum += add;
		for (int j = xSum - add;j >= 0;-- j) {
			dpX[j + add] |= dpX[j];
		}
	}
	memset(dpY, false, sizeof(bool) * MAX);
	dpY[0] = true;
	for (int i = 0;i < yp;++ i) {
		int add = yGo[i];
		ySum += add;
		for (int j = ySum - add;j >= 0;-- j) {
			dpY[j + add] |= dpY[j];
		}
	}
	
	if (xSum >= x && (xSum - x & 1) == 0 && dpX[xSum - x >> 1] && ySum >= y && (ySum - y & 1) == 0 && dpY[ySum - y >> 1]) cout << "Yes"; // 例えば左右に合計100マス動けるとして、目的地が20なら丁度60動けるような部分和があれば移動可能、と考えるよ
	else cout << "No";
	return 0;
}
/*
31536000のコメント解説欄
ここテンプレで用意してるから、A問題とかだとこの先空欄の危険あり
また、コンテスト後に https://31536000.hatenablog.com/ で解説していると思うので、良かったら読んでねー

まず、x方向とy方向はそれぞれ独立に求めることができる
最初に、Tが出てくるまで自分を動かしてしまう
そうすると、残りはどちらの方向にも動けるので、左右か上下ということさえ分かっていれば左と右および上と下の区別をつける必要はない
この時、部分和問題を解けば答えが分かる
*/