#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll MAX=1e15;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	ll a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	ll dp[n+1][n+1];
	ll cost[n+1][n+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cost[i][j]=MAX;
		}
	}
	for(int i=1;i<=n;i++)
	{
		dp[i][i]=a[i-1];
		cost[i][i]=0;
	}
	for(int i=2;i<=n;i++)
	{
		for(int l=1,r=i;r<=n;r++,l++)
		{
			//cost[l][r]=min(cost[l][r],min(a[l-1]+dp[l+1][r]+cost[l+1][r],cost[l][r-1]+dp[l][r-1]+a[r-1]));
			dp[l][r]=a[l-1]+dp[l+1][r];
			for(int j=l;j<r;j++)
			{
				cost[l][r]=min(cost[l][j]+cost[j+1][r]+dp[l][r],cost[l][r]);
			}
		}
	}
	/*int dp2[n+1];
	for(int i=0;i<=n;i++)
	{
		dp2[i]=cost[1][i];
	}*/
	cout<<cost[1][n]<<"\n";

}