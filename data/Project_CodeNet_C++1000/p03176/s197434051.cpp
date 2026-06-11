#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define FASTIO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long int
#define F first
#define S second
#define pll pair<ll,ll>
#define vl vector<ll>
#define vi vector<int>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vpii vector<pair<int,int> >
#define vvpii vector<vpii >
#define vpll vector<pair<ll,ll> >
#define vvpll vector<vpll >
#define pb push_back
#define MOD 1000000007
#define brk cout<<"\n"

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set;

struct compare {
	bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
		if ((a.S - a.F) != (b.S - b.F)) return ((a.S - a.F) > (b.S - b.F));
		else return (a.F < b.F);
	}
};

int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	FASTIO;
	ll n; cin >> n;
	vl h(n), v(n), dp(n + 1);
	ll base = 1;
	while (base <= n) base *= 2;
	vl segtree(2 * base);
	for (ll i = 0; i < n; i++) cin >> h[i];
	for (ll i = 0; i < n; i++)cin >> v[i];

	for (ll i = 0; i < n; i++) {
		ll best = 0;
		ll x = h[i] + base;
		while (x > 1) {
			if (x % 2 == 1) {
				best = max(best, segtree[x - 1]);
			}
			x /= 2;
		}
		dp[h[i]] = best + v[i];
		for (ll j = base + h[i]; j >= 1; j /= 2) {
			segtree[j] = max(segtree[j], dp[h[i]]);
		}
		//cout << dp[h[i]] << endl;
	}

	ll ans = 0;
	for (ll i = 1; i < n + 1; i++)ans = max(ans, dp[i]);
	cout << ans; brk;



}