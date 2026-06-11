// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2")

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <chrono>
#include <vector>
#include <map>
#include <random>
#include <set>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <stdio.h>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <deque>
#include <cassert>
#include <stack>
using namespace std;

#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ppb pop_back
#define ll long long
#define ull unsigned long long
#define cntbit(x) __builtin_popcount(x)
#define endl '\n'
#define uset unordered_set
#define umap unordered_map
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define ld long double
#define pll pair<long long, long long>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline void setin(string s) {
	freopen(s.c_str(), "r", stdin);
}

inline void setout(string s) {
	freopen(s.c_str(), "w", stdout);
}

template <typename T> inline T range(T l, T r) {
	return uniform_int_distribution <T>(l, r)(rng);
}

template <typename T> void Min(T &a, T b) {
    a = min(a, b);
}
 
template <typename T> void Max(T &a, T b) {
    a = max(a, b);
}

#define int long long

const int inf = 2e9;
const int mod = 1e9 + 7;
const int N = 1e5 + 15;
int n;
pii a[N];
multiset <pii> l, r;

inline bool lie(int l, int x, int r) {
	return l <= x && x <= r;
}

inline int d(int x, int y) {
	return abs(x - y);
}

main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	// setin("input.txt");
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].f >> a[i].se;
		l.insert({a[i].f, i});
		r.insert({a[i].se, i});
	}
	l.insert({0, 0});
	r.insert({0, 0});
	int ans = 0, cur = 0, pos = 0;
	for(int i = 1, j; i <= n/2 + 1; ++i) {
			j = l.rbegin()->se;
			cur += a[j].f;
			l.erase({a[j].f, j});

			j = r.begin()->se;
			cur -= a[j].se;
			r.erase({a[j].se, j});

		Max(ans, cur);
	}
	cout << 2 * ans << endl;
	return 0;
}
