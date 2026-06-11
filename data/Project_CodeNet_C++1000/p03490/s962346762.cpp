#include<iostream>
#include<cstring>
#include<bitset>
using namespace std;

const int MAX = 8000;
const char FORWARD = 'F';
const char TURN = 'T';

int main() {
	string s;
	int x, y;
	cin >> s >> x >> y;
	
	const char *S = s.c_str();
	
	for (;*S == FORWARD;++ S) -- x; // 最初の文字数だけxを減らす
	x = x < 0 ? -x : x;
	y = y < 0 ? -y : y;
	
	bitset<MAX> dpX(1), dpY(1); // 部分和問題はdpで解けるよ
	int xSum = 0, ySum = 0, xGo, yGo;
	
	for (++ S;*S != '\0';++ S) {
		xGo = 0, yGo = 0; // 連続した移動の長さ
		for (;*S == FORWARD;++ S) ++ yGo; // y軸方向
		dpY |= dpY << yGo;
		ySum += yGo;
		for (++ S;*S == FORWARD;++ S) ++ xGo; // x軸方向
		dpX |= dpX << xGo;
		xSum += xGo;
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

ちょっと高速化に手を出してみたけど、お陰で闇コードがあるから怖いね
やっぱこういうのやるべきではないわ
*/