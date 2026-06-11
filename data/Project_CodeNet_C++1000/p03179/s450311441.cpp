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

void add_self(ll &a, ll b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

const int mx = 3005;
char cmp[mx];
ll dp[mx][mx], pref[mx][mx];

int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	FASTIO;
	ll n; cin >> n;
	cin >> cmp;
	dp[1][1] = 1;
	for (ll len = 2; len <= n; len++) {
		for (ll i = 1; i <= len - 1; i++) {
			pref[len - 1][i] = (pref[len - 1][i - 1] + dp[len - 1][i]) % MOD;
		}
		for (ll curr = 1; curr <= len; curr++) {
			ll L, R;
			if (cmp[len - 2] == '<') {
				L = 1; R = curr - 1;
			}
			else {
				L = curr, R = len - 1;
			}
			if (L <= R) {
				add_self(dp[len][curr], (pref[len - 1][R] - pref[len - 1][L - 1] + MOD) % MOD);
			}
			// for (ll prev = 1; prev <= len - 1; prev++) {
			// 	ll real_prev = prev;
			// 	if (curr <= prev) real_prev++;
			// 	if ((real_prev < curr) != (cmp[len - 2] == '<')) continue;
			// 	add_self(dp[len][curr], dp[len - 1][prev]);
			// }
		}
	}
	// for (ll i = 0; i < n; i++) {
	// 	for (ll j = 0; j < n; j++) {
	// 		cout << dp[i + 1][j + 1] << " ";
	// 	}
	// 	brk;
	// }
	ll ans = 0;
	for (ll i = 1; i <= n; i++) add_self(ans, dp[n][i]);
	cout << ans; brk;

}