#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll solve(int cost[],int n,int k)
{
	ll dp[n];
	for(int i=0 ; i<n ; i++)
		dp[i]=INT_MAX;
	dp[0]=0;
	for(int i=0 ; i<n ; i++)
	{
		for(int j=1 ; j<=k ; j++)
		if(i+j<n)
			dp[i+j]=min(dp[i+j],dp[i]+abs(cost[i+j]-cost[i]));
	}
	return dp[n-1];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	int cost[n];
	for(int i=0 ; i<n ; i++)
		cin>>cost[i];
	long long int ans=solve(cost,n,k);
	cout<<ans;
	return 0;
}