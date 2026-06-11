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
const int mod = 998244353;
const int N = 2e5 + 15;
const int L = 29;
int n, a[N], b[N];
int ans;
int pw[L + 2];

main() {
	for(int i = 0; i <= L + 1; ++i)
		pw[i] = 1 << i;
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	// setin("input.txt");
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i)
		cin >> b[i];
	for(int j = L; j; --j) {
		for(int i = 1; i <= n; ++i) {
			b[i] &= pw[j] - 1;
			a[i] &= pw[j] - 1;
		}
		sort(b + 1, b + 1 + n);
		int cur = 0;
		for(int i = 1; i <= n; ++i) {
			int x = a[i];
			cur ^= upper_bound(b + 1, b + 1 + n, pw[j] - 1 - x) - lower_bound(b + 1, b + 1 + n, pw[j - 1] - x);
			cur ^= upper_bound(b + 1, b + 1 + n, pw[j + 1] - 1 - x) - lower_bound(b + 1, b + 1 + n, pw[j] + pw[j-1] - x);
		}
		if(cur & 1)
			ans |= pw[j-1];
	}
	cout << ans << endl;
	return 0;
}
