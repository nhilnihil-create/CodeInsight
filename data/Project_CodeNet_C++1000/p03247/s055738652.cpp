#include <iostream>
#include <string>
#include <cmath>
#define int long long
#define rep(i, n) for(i = 0; i < n; i++)
using namespace std;

int n;
int x[1000], y[1000];
const int m = 35;
int d[m];

signed main() {
	int i, j;
	
	cin >> n;
	rep(i, n) cin >> x[i] >> y[i];
	
	int guki = (abs(x[0]) + abs(y[0])) % 2;
	rep(i, n) if (guki % 2 != (abs(x[i]) + abs(y[i])) % 2) { cout << "-1" << endl; return 0; }
	
	int sumD = 0;
	if (guki % 2) {
		rep(i, m) { d[i] = (1LL << i); sumD += d[i]; }
	}
	else {
		rep(i, m - 1) { d[i] = (1LL << i); sumD += d[i]; }
		d[m - 1] = 1; sumD++;
	}
	
	cout << m << endl;
	rep(i, m) {
		cout << d[i];
		if (i + 1 < m) cout << " ";
	}
	cout << endl;
	
	rep(i, n) {
		int xx = x[i] - y[i];
		int yy = x[i] + y[i];
		
		rep(j, m - (guki % 2 == 0)) {
			int p = ((sumD - xx) >> (j + 1)) % 2;
			int q = ((sumD - yy) >> (j + 1)) % 2;
			if (p == 0 && q == 0) cout << "R";
			if (p == 0 && q == 1) cout << "D";
			if (p == 1 && q == 0) cout << "U";
			if (p == 1 && q == 1) cout << "L";
		}
		if (guki % 2 == 0) cout << "R";
		cout << endl;
	}
	return 0;
}
//d_i = 1 … マンハッタン距離の偶奇が全て等しい ⇔ 構成可能。以降マンハッタン距離の偶奇は全て等しいとする。
//1次元：偶→1,1,2,4,8,16,…. 奇→1,2,4,8,16…
//2次元：1次元×2回では回数が足りない。x,y同時に移動できれば… → 45°回転して見ると、実質ななめ移動に。
//命令の重ね合わせができる(L+D→左下、のような感じ）ので、m=40でも余裕。
//45°回転すると、x+yの偶奇が全て同じ⇒x'の偶奇が全て等しい, y'の偶奇が全て等しい, (x'の偶奇==y'の偶奇）
//だから、同じアームを使いまわせる。