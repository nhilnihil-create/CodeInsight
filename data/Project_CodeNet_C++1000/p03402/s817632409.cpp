#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <math.h>

using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; i++)
#define rep(i,b) Rep(i,0,b)
#define rrep(i,a) for(int i = a; i >= 0; i--)
#define allof(a) (a).begin(), (a).end()

typedef long long ll;
const int inf = 1e9 + 7;
const ll infll = 1ll << 60ll;
const ll mod = 1e9 + 7;
// 0~3までは右左下上 4~7までは斜め
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

/*
// 最大公約数
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// 最小公倍数
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}*/

const int MAX = 100;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	// a個の白の連結成分
	// b個の黒の連結成分

	// 長方形(正方形)となる

	// 高さ2、幅1000のフィールドを作る

	vector<vector<char>>field(MAX, vector<char>(MAX,'#'));
	// 上半分を全部白にする
	rep(i, MAX / 2) {
		rep(j,MAX){
			field[i][j] = '.';
		}
	}

	int white = 1;
	int black = 1;

	// 黒を増やす場合　上半分の上から偶数行を一つ置きに黒にする
	// 白を増やす場合 下半分の下から奇数行を一つ置きに白にする

	int bi = 0;
	int bj = 0;
	int wi = MAX - 1;
	int wj = 0;

	while (a != white || b != black) {
		if (a > white) {
			field[wi][wj] = '.';
			wj += 2;
			if (wj >= MAX) {
				wj = 0;
				wi -= 2;
			}
			white++;
		}
		if (b > black) {
			field[bi][bj] = '#';
			bj += 2;
			if (bj >= MAX) {
				bj = 0;
				bi += 2;
			}
			black++;
		}
	}

	cout << MAX <<  " " << MAX << endl;

	rep(i, MAX) {
		rep(j, MAX) {
			cout << field[i][j];
		}
		cout << endl;
	}
	return 0;
}