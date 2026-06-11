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
#pragma endregion

int main() {
	lint n, m; cin >> n >> m;
	vector<lint> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<pair<lint, lint>> d(m);
	for (int i = 0; i < m; i++) cin >> d[i].second >> d[i].first;
	sort(d.rbegin(), d.rend());
	lint cnt = 0;
	for (auto s : d) {
		for (int i = 0; i < s.second; i++) {
			if (cnt > n) goto Cyan;
			a.emplace_back(s.first);
			cnt++;
		}
	}
Cyan:;
	sort(a.rbegin(), a.rend());
	lint ans = 0;
	for (int i = 0; i < n; i++) {
		ans += a[i];
	}
	cout << ans << endl;

	return 0;
}