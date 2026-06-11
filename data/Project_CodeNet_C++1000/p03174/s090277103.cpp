#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;

ll n,dp[22][1<<21],cp[22][22];

ll solve(ll i,ll st){
	
//	cout<<i<<" "<<st<<"\n";
	
	if (dp[i][st]!=-1) return dp[i][st];
	
	ll res=0;
	
	for (ll j=0;j<n;++j){
		if (st&(1LL<<j)) res=(res+cp[i-1][j]*solve(i-1,st^(1LL<<j)))%mod;
	}
	
	return dp[i][st]=res;
}

int main(){
//	freopen("input.inp","r",stdin);
//	freopen("output.out","w",stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	
	for (ll i=0;i<n;++i){
		for (ll j=0;j<n;++j) cin>>cp[i][j];
	}
	
	memset(dp,-1,sizeof(dp));
	
	dp[0][0]=1;
	
/*	for (ll i=0;i<n;++i){
		for (ll st=0;st<(1LL<<n);++st){
			for (ll j=0;j<n;++j){
				if (st&(1LL<<j)) dp[i+1][st]=(dp[i+1][st]+cp[i][j]*dp[i][st^(1LL<<j)])%mod;
			}
			
		}
	}
	
//	for (ll i=1;i<=n;++i)
	
	cout<<dp[n][(1LL<<n)-1]<<"\n";*/
	
	cout<<solve(n,(1LL<<n)-1);
}