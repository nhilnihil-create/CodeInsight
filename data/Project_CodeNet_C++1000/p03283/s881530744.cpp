#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <random>
#include <unordered_map>
#include <unordered_set>
#define all(a) a.begin(),a.end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define pb push_back
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;
typedef complex<ld> com;
constexpr int inf = 1000000000;
constexpr ll INF = 1000000000000000010;
constexpr ld EPS = 1e-12;
constexpr ld PI = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<int>> cnt(n + 1, vector<int>(n + 1));
	rep(i, m) {
		int l, r;
		cin >> l >> r;
		cnt[n + 1 - l][r]++;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cnt[i][j] += cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
		}
	}
	rep(_, q) {
		int l, r;
		cin >> l >> r;
		cout << cnt[n + 1 - l][r] << '\n';
	}
}