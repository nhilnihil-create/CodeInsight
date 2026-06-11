#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> c(n);
	rep(i, n) cin >> c[i];

	vector<ll> dp(n+1, 0);
	vector<ll> dp2(202020, 0);
	dp[0] = 1;

	rep(i, n){
		if(c[i-1] == c[i]){
			dp[i+1] = dp[i];
		}else{
			dp[i+1] = dp[i] + dp2[c[i]];
			dp[i+1] %= MOD;

			dp2[c[i]] += dp[i];
			dp2[c[i]] %= MOD;
		}
	}

	cout << dp[n] << endl;

}
