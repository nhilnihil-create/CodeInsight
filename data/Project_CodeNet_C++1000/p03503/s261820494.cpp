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

	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(10));
	rep(i, n) rep(j, 10) cin >> a[i][j];
	vector<vector<int>> cnt(n, vector<int>(11));
	rep(i, n) rep(j, 11) cin >> cnt[i][j];
	int ans = -inf;
	for (int i = 1; i < 1024; i++) {
		int res = 0;
		rep(j, n) {
			int c = 0;
			rep(k, 10) {
				if (((i >> k) & 1) && a[j][k]) c++;
			}
			res += cnt[j][c];
		}
		chmax(ans, res);
	}
	cout << ans << '\n';
}