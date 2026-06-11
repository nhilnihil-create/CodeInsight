#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define inf (1LL << 60)

ll sum[420][420];
ll dp[420][420];

void preprocess(ll a[], ll n) {

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			sum[i][j] = a[j] + ((i == j) ? 0 : sum[i][j - 1]);
		}
	}
}

ll solve(ll s, ll f) {
	// cout << s << " , " << f << endl;
	if (s >= f)
		return 0;

	if (dp[s][f] != -1) return dp[s][f];

	ll add = inf;
	for (int k = s; k < f; k++) {
		add = min(solve(s, k) + solve(k + 1, f) + sum[s][f], add);
	}

	return dp[s][f] = add;
}


int main() {


	int n;
	cin >> n;

	ll a[n + 1];
	for (int i = 1; i <= n; i++) cin >> a[i];

	preprocess(a, n);
	memset(dp, -1, sizeof dp);

	cout << solve(1, n) << endl;

	return 0;
}