#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const long long MOD  = 1e9 +7;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	ll n,k;
	cin >>n>>k;
	vector<ll> v(n);
	for(int i = 0;i < n; i++) cin >> v[i];
	vector<ll> dp(k+1), end(k+1);
	ll ans = 0;
	dp[0]  = 1;
	for(int i = 0;i < n; i++) {
		 ans  = 0;
		 for(int j = 0;j <= k;j++) {
			 ans = (ans+dp[j])%MOD;
		 	 if(j + v[i]<k) end[j+v[i]] = dp[j];
		 	 dp[j] = ans;
		 	 ans = (((ans - end[j])%MOD)+MOD) %MOD;
		 	 end[j] = 0;
		 }
	}
	cout <<dp[k]<<'\n';
	return 0;
}
