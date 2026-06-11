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
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	for (int i = 1; i < n; i++) a[i] += a[i - 1];
	ll ans = INF;
	for (int i = 1; i < n - 2; i++) {
		ll mi = -INF; ll ma = INF;
		ll leftsum = a[i];
		ll leftidx = lower_bound(all(a), leftsum / 2) - a.begin();
		if (leftidx != i) update(mi, ma, a[leftidx], a[i] - a[leftidx]);
		leftidx--;
		if (leftidx != -1) update(mi, ma, a[leftidx], a[i] - a[leftidx]);
		ll mi2 = -INF; ll ma2 = INF;
		ll rightsum = a[n - 1] - a[i];
		ll rightidx = lower_bound(all(a), leftsum + rightsum / 2) - a.begin();
		if (rightidx != n - 1) update(mi2, ma2, a[rightidx] - a[i], a[n - 1] - a[rightidx]);
		rightidx--;
		if (rightidx != i) update(mi2, ma2, a[rightidx] - a[i], a[n - 1] - a[rightidx]);
		chmin(ans, max(ma, ma2) - min(mi, mi2));
	}
	cout << ans << '\n';
}