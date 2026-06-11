#include<bits/stdc++.h>

using namespace std;

const long long maxn = 3e5+7, mod = 1e9+7, inf = 1e9;
long long n, dp_help[maxn], dp[maxn], a[maxn], ans;

int main() {
	
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	dp[0] = 1;
	for (int i = 1; i <= n; i ++) {
		if (a[i] != a[i - 1]) dp_help[a[i]] += dp[i - 1] , dp[i] = dp_help[a[i]];
		else dp[i] = dp[i - 1];
		dp[i] %= mod , dp_help[a[i]] %= mod;
	}
	cout << dp[n] << endl;

	return 0;

}