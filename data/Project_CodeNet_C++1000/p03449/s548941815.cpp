#include<bits/stdc++.h>
using namespace std;	
int n,dp[3][1000],a[3][1000];
int main()
{

	cin>>n;
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j];
		}
	}
	cout<<dp[2][n];
}