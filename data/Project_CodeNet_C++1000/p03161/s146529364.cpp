#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE
	int n,k;
	cin>>n>>k;
	int arr[n];
	int dp[n];
	for(int i=0;i<n;i++)
		dp[i]=1e9;
	dp[0]=0;
	for(int i=0;i<n;i++)
		cin>>arr[i];

	for(int i=0;i<n-1;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(i+j<n)
				dp[i+j]=min(dp[i+j],dp[i]+abs(arr[i+j]-arr[i]));
		}
	}
	cout<<dp[n-1]<<"\n";
	// for(int i=0;i<n;i++)
	// 	cout<<dp[i]<<"\n";
}