#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[400];
ll dp[400][400];
ll Cost(ll i,ll j)
{
	ll sum=0;
	for(ll idx=i;idx<=j;idx++)
		sum+=arr[idx];
	return sum;
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
	cout<<MinCost(0,n-1);
}