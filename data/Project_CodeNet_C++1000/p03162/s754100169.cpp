#include<bits/stdc++.h>
using namespace std;
typedef long long 	ll;
const ll 	MOD		=  	1e+9+7;
const ll 	N 		= 	2*1e6+5;
ll dp[N][5];
ll a[N][5];
ll n;
ll solve(ll i,ll p)
{
	if(i==n)
	{
		return 0;
	}
	if(dp[i][p]!=-1)
	{
		return dp[i][p];
	}
	ll ans=-1e9;
	for(ll j=0;j<3;j++)
	{
		if(j==p)
		{
			continue;
		}
		ans=max(ans,solve(i+1,j)+a[i][j]);
	}
	return dp[i][p]=ans;
}
 
int main() {
 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
 
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<3;j++)
		{
			cin>>a[i][j];
		}
	}
	memset(dp,-1,sizeof(dp));
	cout<<solve(0,3);
}