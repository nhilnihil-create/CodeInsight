#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll solve(int cost[],int n)
{
	ll dp[n];
	for(int i=0 ; i<n ; i++)
		dp[i]=INT_MAX;
	dp[0]=0;
	for(int i=0 ; i<n ; i++)
	{
		if(i+1<n)
			dp[i+1]=min(dp[i+1],dp[i]+abs(cost[i+1]-cost[i]));
		if(i+2<n)
			dp[i+2]=min(dp[i+2],dp[i]+abs(cost[i+2]-cost[i]));
	}
	return dp[n-1];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int cost[n];
	for(int i=0 ; i<n ; i++)
		cin>>cost[i];
	long long int ans=solve(cost,n);
	cout<<ans;
	return 0;
}