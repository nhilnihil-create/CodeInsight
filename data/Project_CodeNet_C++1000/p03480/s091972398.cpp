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

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	int k = inf; // 最大の整数K

	// 左右に隣り合う2つをすべての操作に対して同じ対応をしてしまうと
	// その2つの色は同じまま
	// もしその2つが違う数字ならば、アウト
	// よって違う数字で隣り合う場合は、その真ん中を右端または左端
	// としなきゃならない

	// 全部白、黒なら別の対応をする
	int wNum = 0;
	int bNum = 0;
	rep(i, (int)s.size()) {
		if (s[i] == '0') wNum++;
		else bNum++;
	}

	if (wNum == 0 || bNum == 0) {
		cout << (int)s.size() << endl;
		return 0;
	}

	Rep(i, 1, (int)s.size()) {
		if (s[i] != s[i - 1]) {
			k = min(k, max(i, (int)s.size() - i));
		}
	}

	cout << k << endl;

	return 0;
}