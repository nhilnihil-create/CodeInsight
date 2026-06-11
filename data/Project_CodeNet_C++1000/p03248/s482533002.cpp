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

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e5 + 15;
int n, p[N];
string s;

int sz[N];

inline bool check(string s) {
	string t = s;
	reverse(t.begin(), t.end());
	return t == s;
}

main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	// setin("input.txt");
	cin >> s;
	n = s.size();
	s = "0" + s;
	if(!check(s) || s[1] == '0' || s[n] == '1')
		return cout << -1 << endl, 0;
	for(int i = 1; i <= n; ++i)
		p[i] = i-1;
	sz[1] = 1;
	for(int i = 2; i < n; ++i) {
		sz[i] = i;
		// sz[i] = sz[p[i]] + 1;
		if(s[n - i + 1] == '0') {
			p[i+1] = p[i];
		}
	}
	for(int i = 2; i <= n; ++i)
		cout << p[i] << ' ' << i << endl;
	return 0;
}