#include <bits/stdc++.h>
#define read(n) scanf("%lld",&n)
#define write(x) printf("%lld",x)
#define F(i,n) for(int i = 0;i < n;i++)
#define ll long long
#define MX 3005
#define MOD 1000000007
#define INF 1000000009
#define set_dp(dp) memset(dp,-1,sizeof(dp))
using namespace std;
ll n, dp[MX][MX];
string s;
ll solve(ll i, ll j){
	if(i == 0) return j == 0;
	if(j < 0 || j > i) return 0;
	if(dp[i][j] == -1){
		ll ans = 0;
		if(s[i - 1] == '<')
			ans = (solve(i, j - 1) + solve(i - 1, j - 1)) % MOD;
		else
			ans = (solve(i, j + 1) + solve(i - 1, j)) % MOD;
		dp[i][j] = ans;
	}
	return dp[i][j];
}
int main(){

	cin>>n>>s;

	set_dp(dp);

	ll ans = 0;

	F(j, n){
		ans += solve(n - 1, j);
		ans %= MOD;
	}

	write(ans);

	return 0;
}
