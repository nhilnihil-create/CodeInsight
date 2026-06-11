// " --- IN THE NAME OF ALLAH --- " // ;)
// ------------sphr_agz------------ // ;)
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

typedef long double ld;
typedef long long int lli;
typedef pair <lli, lli> pii;
#define pb push_back
#define recout(x) return cout << (x), 0
#define f first
#define s second
#define fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define stp(x) cout << setprecision(x) << fixed
#define mk make_pair
#define all(x) x.begin(), x.end()
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
const lli N = 2e5 + 10, N2 = 2e5, delta = 46639, mod = 1e9 + 7, oo = 1e18, LOG = 20, SQ = 300;
const ld PI = 3.141592653589793;

lli h[N], a[N], dp[N], mx[N << 2];

void add (lli ind, lli val, lli l = 0, lli r = N, lli id = 1) {
	if (r - l <= 1) {
		mx[id] = val;
		return;
	}
	lli mid = (r + l) / 2;
	if (ind < mid)
		add (ind, val, l, mid, 2 * id);
	else
		add (ind, val, mid, r, 2 * id + 1);
	mx[id] = max (mx[2 * id], mx[2 * id + 1]);
}

lli get (lli l, lli r, lli b = 0, lli e = N, lli id = 1) {
	if (l <= b && e <= r)
		return mx[id];
	lli mid = (b + e) / 2, ans = 0;
	if (l < mid)
		ans = max (ans, get (l, r, b, mid, 2 * id));
	if (mid < r)
		ans = max (ans, get (l, r, mid, e, 2 * id + 1));
	return ans;
}

int32_t main() {
	fast;
	lli n, ans = 0;
	cin >> n;
	for (lli i = 0; i < n; i++)
		cin >> h[i];
	for (lli i = 0; i < n; i++)
		cin >> a[i];
	dp[0] = a[0];
	ans = a[0];
	add (h[0] - 1, a[0]);
	for (lli i = 1; i < n; i++) {
		dp[i] = get (0, h[i] - 1) + a[i];
		add (h[i] - 1, dp[i]);
		//cout << dp[i] << '\n';
		ans = max (ans, dp[i]);
	}
	cout << ans << '\n';
	return 0;
}
