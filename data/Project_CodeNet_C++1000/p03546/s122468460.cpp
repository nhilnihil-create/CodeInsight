#pragma region header
#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cctype>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
#include <cstring>
#include <array>
// ===============================================================
//using系
#pragma region header
using namespace std;
using lint = long long;
using ld = long double;
using ulint = unsigned long long;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };
constexpr lint mod = 1000000007;
constexpr long double pi = 3.141592653589793238462643383279;
#pragma endregion
// ========================================================================
//define
#define INF (lint)10000000000000000;
#define mod (int)1000000007
#pragma region header
template <class T, class U>
inline bool chmin(T& lhs, const U& rhs) {
	if (lhs > rhs) {
		lhs = rhs;
		return 1;
	}
	return 0;
}
template <class T, class U>
inline bool chmax(T& lhs, const U& rhs) {
	if (lhs < rhs) {
		lhs = rhs;
		return 1;
	}
	return 0;
}
#pragma endregion
#pragma endregion

int h, w;
vector<vector<int>> d;
vector<vector<int>> memo(10, vector<int>(10));
void input() {
	cin >> h >> w;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			cin >> memo[i][j];
	d.resize(h);
	for (int i = 0; i < h; i++) {
		d[i].resize(w);
		for (int j = 0; j < w; j++)
			cin >> d[i][j];
	}
	return;
}
void wf() {
	for (int i = 0; i < 10; i++)
		memo[i][i] = 0;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 10; k++)
				memo[j][k] = min(memo[j][k], memo[j][i] + memo[i][k]);
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	wf();
	lint ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (d[i][j] == -1) continue;
			ans += memo[d[i][j]][1];
		}
	}
	cout << ans << endl;

	return 0;
}