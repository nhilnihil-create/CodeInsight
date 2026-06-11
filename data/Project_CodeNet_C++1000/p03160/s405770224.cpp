#include<bits/stdc++.h>
using namespace std;
int dp[10000001];
int arr[10000001];
int n;
int solve(int ind)
{
	if(ind==n-1)
	{
		return 0;
	}
	if(dp[ind]!=-1)
	{
		return dp[ind];
	}
	int ans=solve(ind+1)+abs(arr[ind+1]-arr[ind]);
	if(ind+2<n)
	{
		ans=min(ans,solve(ind+2)+abs(arr[ind+2]-arr[ind]));
	}
	return dp[ind]=ans;


}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<solve(0)<<"\n";
	return 0;
}