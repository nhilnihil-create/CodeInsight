#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[401][401];
ll sum[401][401];
ll a[401];
ll solve(ll n)
{
	for(ll p=1;p<=n;p++)
	{
		dp[p][p]=0;
	}
	for(ll i=1;i<=n;i++)
	{
		sum[i][i]=a[i];
		for(ll j=i+1;j<=n;j++)
		{
			sum[i][j]=sum[i][j-1]+a[j];
		}
	}
	for(ll length=2;length<=n;length++)
	{
		for(ll i=1;i<=n-length+1;i++)
		{
			ll j=i+length -1;
			dp[i][j]=1e14;
			for(ll k=i;k<=j;k++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[i][j]);
			}
		}
	}
	return dp[1][n];
}
int main()
{
	ll n;
	cin>>n;
	for(ll p=1;p<=n;p++)
	{
		cin>>a[p];
	}
	cout<<solve(n);
}