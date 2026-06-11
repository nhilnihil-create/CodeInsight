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



int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s, t; cin >> s >> t;
	vector<string> d;
	for (int i = 0; i < (int)s.length(); i++) {
		if (i + t.length() > s.length()) break;
		string c = s;
		for (int j = 0; j < (int)t.length(); j++) {
			if (s[i + j] != '?' && t[j] != s[i + j]) goto Cyan;
			c[i + j] = t[j];
		}
		for (int j = 0; j < (int)c.length(); j++) if (c[j] == '?') c[j] = 'a';
		d.emplace_back(c);
	Cyan:;
	}
	sort(d.begin(), d.end());
	if (d.size() == 0) cout << "UNRESTORABLE" << endl;
	else cout << d[0] << endl;

	return 0;
}