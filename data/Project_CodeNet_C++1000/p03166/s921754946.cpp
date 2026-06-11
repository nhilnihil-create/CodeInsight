#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back

vector<ll> gr[100005];
ll dp[100005];

ll solve(ll node) {
	if (dp[node] != -1)
		return dp[node];

	bool leaf = true;
	ll ans = 0;
	for (ll child : gr[node]) {
		leaf = false;
		ans = max(ans, solve(child));
	}

	return dp[node] = (leaf) ? (0) : (1 + ans);
}

void fast() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef tmr
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int  main() {
	ll n , m;
	cin >> n >> m;

	memset(dp, -1, sizeof dp);

	for (int i = 0; i < m; i++) {
		ll s, f;
		cin >> s >> f;
		gr[s].pb(f);
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, solve(i));
	}

	cout << ans << endl;
	return 0;
}