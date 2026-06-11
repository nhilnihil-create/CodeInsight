#include<bits/stdc++.h>
using namespace std;


int solve()
{
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	if(n==1)
	return 0;
	
	if(n==2)
	return abs(arr[0]-arr[1]);
	
	int dp[n];
	dp[0]=0;
	dp[1]=abs(arr[0]-arr[1]);
	
	for(int i=2;i<n;i++)
	{
		dp[i]=min(dp[i-2]+abs(arr[i-2]-arr[i]),dp[i-1]+abs(arr[i-1]-arr[i]));
	}
	return dp[n-1];
}
int main()
{
	cout<<solve();	
}
