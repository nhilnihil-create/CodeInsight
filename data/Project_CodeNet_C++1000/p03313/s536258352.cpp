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
#define all(a) a.begin(),a.end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
typedef complex<ld> com;
constexpr int inf = 1000000000;
constexpr ll INF = 1000000000000000000;
constexpr ld EPS = 1e-12;
constexpr ld PI = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }

void update(ll &mi, ll &ma, ll val, ll val2) {
	if (val > val2) swap(val, val2);
	chmax(mi, val); chmin(ma, val2);
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	int n;
	cin >> n;
	int m = (1 << n);
	vector<int> a(m);
	rep(i, m) cin >> a[i];
	vector<P> dp(m), dp2(m);
	dp[0] = P(a[0], 0); dp2[0] = P(-inf, -1);
	int ans = 0;
	for (int i = 1; i < m; i++) {
		vector<P> ok;
		rep(j, n) {
			if ((i >> j) & 1) {
				int b = (1 << j);
				ok.pb(P(a[i], i)); ok.pb(dp[i - b]); ok.pb(dp2[i - b]);
				if (i != b) {
					ok.pb(dp[b]); ok.pb(dp2[b]);
				}
			}
		}
		sort(all(ok)); reverse(all(ok));
		int sum = 0; int idx = -1; int cnt = 0;
		for (P j : ok) {
			if (j.second != idx) {
				sum += j.first;
				idx = j.second;
				if (cnt == 0) dp[i] = j;
				if (cnt == 1) dp2[i] = j;
				cnt++;
				if (cnt == 2) break;
			}
		}
		chmax(ans, sum);
		cout << ans << '\n';
	}
}