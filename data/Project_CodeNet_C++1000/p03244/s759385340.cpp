// type a
//a...いけそう
//b...自信がない
//c...お試し
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
#include <list>
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
#pragma endregion



int main() {
	int n; cin >> n;
	vector<int> d(n);
	vector<pair<int, int>> a(100010);
	vector<pair<int, int>> b(100010);
	for (int i = 0; i < 100010; i++) {
		a[i] = make_pair(0, i);
		b[i] = make_pair(0, i);
	}
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		if (i % 2 == 0) a[d[i]].first++;
		else b[d[i]].first++;
	}
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());
	if (a[0].second != b[0].second) {
		cout << n - a[0].first - b[0].first << endl;
	}
	else {
		cout << min(n - a[0].first - b[1].first, n - a[1].first - b[0].first) << endl;
	}

	return 0;
}