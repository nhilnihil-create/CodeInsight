/*

This Submission is to determine how many 120/240 min const. delivery point there are.

//info
120 req. steps <= 5
*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 1e-5
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)

unsigned long xor128() {
	static unsigned long x = time(NULL), y = 362436069, z = 521288629, w = 88675123;
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
double dot(complex<double> a, complex<double> b) {
	return a.real() * b.real() + a.imag() * b.imag();
}
double gyaku_dot(complex<double> a, complex<double> b) {
	return a.real() * b.imag() - a.imag() * b.real();
}
double leng(complex<double> a) {
	return sqrt(a.real() * a.real() + a.imag() * a.imag());
}
double angles(complex<double> a, complex<double> b) {
	double cosine = dot(a, b) / (leng(a) * leng(b));
	double sine = gyaku_dot(a, b) / (leng(a) * leng(b));
	double kaku = acos(min((double)1.0, max((double)-1.0, cosine)));
	if (sine <= 0) {
		kaku = 2 * Ma_PI - kaku;
	}
	return kaku;
}
vector<int> convex_hull(vector<complex<double>> a) {
	vector<int> ans;
	double now_minnest = a[0].real();
	int now_itr = 0;
	REP(i, a.size()) {
		if (now_minnest > a[i].real()) {
			now_minnest = a[i].real();
			now_itr = i;
		}
	}
	ans.push_back(now_itr);
	complex<double> ba(0, 1);
	while (true) {
		int now_go = 0;
		double now_min = 0;
		double now_length = 0;
		int starter = ans[ans.size() - 1];
		for (int i = 0; i < a.size(); ++i) {
			if (i != starter) {
				double goa = angles(ba, a[i] - a[starter]);
				if (goa - now_min >= eps || (abs(goa - now_min) <= eps && (abs(a[i] - a[starter]) - now_length) >= eps)) {
					now_min = goa;
					now_go = i;
					now_length = abs(a[i] - a[starter]);
				}
			}
		}
		if (now_go == ans[0]) break;
		ans.push_back(now_go);
		ba = complex<double>(a[now_go] - a[starter]);
	}
	return ans;
}
int dp[302][302][302];
int visited[400][400];
int k = 0;
string s;
void solve(int left, int right) {
	if (left > right) return;
	if (visited[left][right] == 1) return;
	visited[left][right] = 1;
	solve(left + 1, right);
	for (int q = 0; q <= k; ++q) {
		dp[left][right][q] = max(dp[left][right][q], dp[left + 1][right][q]);
		dp[left][right][q + 1] = max(dp[left][right][q], dp[left][right][q + 1]);
	}
	solve(left, right - 1);
	for (int q = 0; q <= k; ++q) {
		dp[left][right][q] = max(dp[left][right][q], dp[left][right - 1][q]);
		dp[left][right][q + 1] = max(dp[left][right][q], dp[left][right][q + 1]);
	}
	solve(left + 1, right - 1);
	for (int q = 0; q <= k; ++q) {
		if (s[left] == s[right]) {
			dp[left][right][q] = max(dp[left][right][q], dp[left + 1][right - 1][q]+2);
		}
		else {
			dp[left][right][q + 1] = max(dp[left][right][q + 1], dp[left + 1][right - 1][q] + 2);
		}
		dp[left][right][q + 1] = max(dp[left][right][q], dp[left][right][q+1]);
	}
}
int main() {
	cin >> s;
	cin >> k;
	for (int i = 0; i < s.length(); ++i) {
		REP(j, k + 1) {
			dp[i][i][j] = 1;
		}
		visited[i][i] = 1;
	}
	for (int i = 0; i < s.length() - 1; ++i) {
		REP(j, k + 1) {
			if (s[i] == s[i + 1]) {
				dp[i][i + 1][j] = 2;
			}
			else {
				dp[i][i + 1][j + 1] = 2;
			}
		}
	}
	solve(0, s.length() - 1);
	int ans = 0;
	REP(j, k + 1) {
		ans = max(ans, dp[0][s.length() - 1][j]);
	}
	cout << ans << endl;
}