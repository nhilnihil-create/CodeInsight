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

class UnionFind {
public:
	vector<int> par;

	UnionFind(int n) : par(n, -1) { }

	int root(int x) {
		if (par[x] < 0) return x;
		else return par[x] = root(par[x]);
	}

	bool same(int x, int y) {
		return root(x) == root(y);
	}

	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if (x == y) return false;
		if (par[x] > par[y]) swap(x, y); // merge technique
		par[x] += par[y];
		par[y] = x;
		return true;
	}

	int size(int x) {
		return -par[root(x)];
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	lint n, m; cin >> n >> m;
	lint ans = n * (n - 1) / 2;
	vector<pair<int, int>> d(m);
	for (int i = 0; i < m; i++) 
		cin >> d[i].first >> d[i].second;
	UnionFind u(n);
	vector<lint> Finalans(m);
	for (int i = m - 1; i >= 0; --i) {
		Finalans[i] = ans;
		int a = d[i].first - 1;
		int b = d[i].second - 1;
		if (!u.same(a, b)) {
			ans -= u.size(a) * u.size(b);
			u.unite(a, b);
		}
	}
	for (int i = 0; i < m; i++) cout << Finalans[i] << endl;

	return 0;
}