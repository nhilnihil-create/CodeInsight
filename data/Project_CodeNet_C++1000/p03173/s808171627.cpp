#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const ll mod = 1e9+7;
const ll nax = 4e2+2;
const ll INF = 1e18;

ll n,dp[nax][nax],a[nax],pr[nax];

int main(){
//	freopen("input.inp","r",stdin);
//	freopen("output.out","w",stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for (ll i=1;i<=n;++i) cin>>a[i];
	

	for (ll i=1;i<=n;++i) pr[i]=pr[i-1]+a[i];
	
	for (ll i=0;i<nax;++i){
		for (ll j=0;j<nax;++j) dp[i][j]=INF;
	}
	
	for (ll l=n;l>=1;--l){
		for (ll r=l;r<=n;++r){
			
			if (r-l==0) dp[l][r]=0;
			else if (r-l==1) dp[l][r]=a[r]+a[l];
			
			else {
				for (ll t=l;t<=r;++t){
					dp[l][r]=min(dp[l][r],dp[l][t]+dp[t+1][r]+pr[r]-pr[l-1]);
				}
			}
			
		}
	}
	
/*	for (ll i=1;i<=n;++i){
		for (ll j=1;j<=n;++j) cout<<((dp[i][j]!=INF)? dp[i][j] : 0 )<<" ";
		cout<<"\n";
	}
	cout<<"\n";*/
	
	cout<<dp[1][n]<<"\n";
	
}