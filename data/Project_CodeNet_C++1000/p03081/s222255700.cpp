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
#include <list>

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
	return a / gcd(a, b) * b;
}*/

bool check(vector<char>t, vector<char>d, int m, int q, string s) {
	int x = m;
	bool ok = false;
	rep(i, q) {
		if (t[i] == s[x]) {
			if (d[i] == 'L') x--;
			else x++;
		}
		if (x < 0) {
			ok = true;
			break;
		}
	}
	return ok;
}

bool checkR(vector<char>t, vector<char>d, int m, int q, string s) {
	int x = m;
	bool ok = false;
	rep(i, q) {
		if (t[i] == s[x]) {
			if (d[i] == 'L') x--;
			else x++;
		}
		if (x >= (int)s.size()) {
			ok = true;
			break;
		}
	}
	return ok;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<char>t(q), d(q);
	rep(i, q) cin >> t[i] >> d[i];

	// 2分探索で境界線を探す
	int left = 0;
	int right = n - 1;
	int mid = (left + right) / 2;

	while (left <= right) {
		// mid番目のマスが条件を満たすか考える
		bool ok = check(t, d, mid, q, s);
		if (!ok) {
			// もっと左のやつを試す
			right = mid - 1;
			mid = (left + right) / 2;
		}
		else {
			left = mid + 1;
			mid = (left + right) / 2;
		}
	}

	// 正確な位置を探す
	if (check(t, d, mid, q, s)) {
		// 一つ右を見る
		if (mid < n - 1) {
			if (check(t, d, mid + 1, q, s)) mid++;
		}
	}
	else {
		mid--;
	}

	// 右から見る
	left = 0; right = n - 1;
	int midR = (left + right) / 2;
	while (left <= right) {
		// mid番目のマスが条件を満たすか考える
		bool ok = checkR(t, d, midR, q, s);
		if (ok) {
			// もっと左のやつを試す
			right = midR - 1;
			midR = (left + right) / 2;
		}
		else {
			left = midR + 1;
			midR = (left + right) / 2;
		}
	}

	// 正確な位置を探す
	if (checkR(t, d, midR, q, s)) {
		// 一つ左を見る
		if (midR > 0) {
			if (checkR(t, d, midR + 1, q, s)) midR--;
		}
	}
	else {
		midR++;
	}

	//cout << mid << " " << midR << endl;

	if (mid >= midR) cout << 0 << endl;
	else cout << midR - mid - 1 << endl;

	return 0;
}
