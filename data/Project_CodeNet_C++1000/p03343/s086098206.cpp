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

const int inf = 2e9;
const int mod = 1e9 + 7;
const int N = 2e3 + 15;
int n, k, q, a[N];
int len[N];
int ord[N];

main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	// setin("input.txt");
	cin >> n >> k >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		ord[i] = i;
	}
	sort(ord + 1, ord + 1 + n, [&](int x, int y) {
		return a[x] > a[y];
	});
	int ans = inf;
	for(int i = 1; i <= n; ++i) {
		int x = a[ord[i]];
		int cur = 0;
		vector <pii> v = {};
		for(int j = 1; j <= n; ++j) {
			if(a[j] < x)
				continue;
			int k = j;
			while(k + 1 <= n && a[k+1] >= x)
				++k;
			for(int t = j; t <= k; ++t)
				v.pb({a[t], j});
			len[j] = k - j + 1;
			j = k;
		}
		sort(v.begin(), v.end());
		int cnt = 0;
		for(pii e : v) {
			if(len[e.se] < k)
				continue;
			--len[e.se], ++cnt;
			if(cnt == q) {
				Min(ans, e.f - x);
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}