#include<bits/stdc++.h>
#define ll long long int
#define inf 1e18
#define mod 1000000007
#define setbits(x) __builtin_popcount(x)
using namespace std;

//-------------------------------------------------------
vector<ll>prefix;
vector<vector<ll>>dp;

ll func(ll i, ll j) {
	if (i >= j) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	ll ans = inf;
	ll sum = prefix[j] - ((i == 0) ? 0 : prefix[i - 1]);
	for (ll cut = i; cut < j; cut++) {
		ll left = func(i, cut);
		ll right = func(cut + 1, j);
		ans = min(ans, sum + left + right);
	}
	return dp[i][j] = ans;
}

int main() {
	ll n; cin >> n;
	ll a[n];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}

	prefix.resize(n);
	prefix[0] = a[0];
	for (ll i = 1; i < n; i++) {
		prefix[i] = prefix[i - 1] + a[i];
	}

	dp.resize(n + 1, vector<ll>(n + 1, -1));
	cout << endl << func(0, n - 1);
	return 0;
}