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

	int n, c;
	cin >> n >> c;
	vector<vector<int>> d(c, vector<int>(c));
	rep(i, c) rep(j, c) cin >> d[i][j];
	vector<vector<int>> a(n, vector<int>(n));
	rep(i, n) rep(j, n) cin >> a[i][j];
	vector<vector<int>> change(3, vector<int>(c));
	rep(x, n) {
		rep(y, n) {
			rep(z, c) {
				if ((x + y) % 3 == 0) change[0][z] += d[a[x][y] - 1][z];
				else if ((x + y) % 3 == 1) change[1][z] += d[a[x][y] - 1][z];
				else change[2][z] += d[a[x][y] - 1][z];
			}
		}
	}
	int ans = inf;
	rep(i, c) {
		rep(j, c) {
			rep(k, c) {
				if (i == j || j == k || k == i) continue;
				chmin(ans, change[0][i] + change[1][j] + change[2][k]);
			}
		}
	}
	cout << ans << '\n';
}