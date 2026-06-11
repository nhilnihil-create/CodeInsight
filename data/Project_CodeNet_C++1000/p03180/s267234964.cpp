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
const lli N = 1e6 + 10, N2 = 2e5, delta = 10067, mod = 1234, oo = 1e9, LOG = 20, SQ = 300;
const ld PI = 3.141592653589793;

lli a[LOG][LOG], dp[N];
vector <lli> v[N];

int32_t main() {
	fast;
	lli n;
	cin >> n;
	for (lli i = 0; i < n; i++)
		for (lli j = 0; j < n; j++)
			cin >> a[i][j];
	for (lli mask = 0; mask < (1 << n); mask++)
		for (lli i = 0; i < n; i++)
			if (mask & (1 << i))
				v[mask].pb(i);
	for (lli mask = 0; mask < (1 << n); mask++) {
		for (lli i: v[mask])
			for (lli j: v[mask])
				dp[mask] += a[i][j];
		dp[mask] /= 2;
	}
	for (lli mask = 0; mask < (1ll << n); mask++)
		for (lli sub = mask; sub; sub = (sub - 1) & mask)
			dp[mask] = max (dp[mask], dp[sub] + dp[mask ^ sub]);
	cout << dp[(1 << n) - 1] << '\n';
	return 0;
}
