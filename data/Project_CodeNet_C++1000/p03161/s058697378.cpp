#include<bits/stdc++.h>
using namespace std;


int dp[100001][101];
int minCost(int * arr,int n,int idx,int k)
{
	if(idx==n-1)
	return 0;
	
	if(dp[idx][k]!=-1)
	return dp[idx][k];
	
	int ans=INT_MAX;
	for(int d=1;d<=k;d++)
	{
		if(idx+d<n)
		ans=min(ans,abs(arr[idx]-arr[idx+d])+minCost(arr,n,idx+d,k));
	}
	dp[idx][k]=ans;
	return ans;
}

int main()
{
		int n,k;
	cin>>n>>k;
	
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	memset(dp,-1,sizeof(dp));
	cout<<minCost(arr,n,0,k);
}
