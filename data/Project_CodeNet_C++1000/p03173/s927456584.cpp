#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[400],pref[400];
ll dp[400][400];
ll Cost(ll i,ll j)
{
	if(i==0)
		return pref[j];
	return pref[j] - pref[i-1];
}
ll MinCost(ll i,ll j)
{
	if(i>=j)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	ll mincost=1e18,cost=Cost(i,j);
	for(ll k=i;k<j;k++)
		mincost=min(mincost,MinCost(i,k)+MinCost(k+1,j)+cost);
	return dp[i][j] = mincost;
}
int main()
{
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++)
		cin>>arr[i];
	memset(dp,-1,sizeof(dp));
	pref[0]=arr[0];
	for(ll i=1;i<n;i++)
		pref[i]=pref[i-1]+arr[i];
	cout<<MinCost(0,n-1);
}