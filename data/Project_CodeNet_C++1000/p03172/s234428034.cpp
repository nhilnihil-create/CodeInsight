#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const ll mod = 1e9+7;
const ll nax = 1e5+7;
const ll INF = 1e18;

ll n,k,a[102];
ll dp[102][nax],BIT[102][nax];

void update(ll id,ll x,ll val){
	for (ll i=x;i<nax;i=i|(i+1)) BIT[id][i]=(BIT[id][i]+val)%mod;
}

ll sum(ll id,ll x){
	ll res=0;
	for (ll i=x;i>=0;i=(i&(i+1))-1) res=(res+BIT[id][i])%mod;
	return res;
}

int main(){
//	freopen("input.inp","r",stdin);
//	freopen("output.out","w",stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>k;
	
	for (ll i=0;i<n;++i) cin>>a[i];
	
	dp[0][0]=1;
	update(0,0,1);
	for (ll i=0;i<n;++i){
		for (ll j=0;j<=k;++j){
			dp[i+1][j]=((dp[i+1][j]+sum(i,j)- ((j>a[i])? sum(i,j-a[i]-1) : 0))%mod+mod)%mod;
			update(i+1,j,dp[i+1][j]);
		}
	}
	
	cout<<dp[n][k];
}