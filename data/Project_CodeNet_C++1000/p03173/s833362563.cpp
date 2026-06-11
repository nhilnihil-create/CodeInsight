#include<bits/stdc++.h>
using namespace std;
long long int inf=1e18+5;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,i;
	cin>>n;
	long long int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	long long int dp[n][n];
	memset(dp,0,sizeof(dp));
	int j,l,k;
	for(i=0;i<n;i++)
		dp[i][i]=0;
	long long int sum[n];
	sum[0]=a[0];
	for(i=1;i<n;i++)
		sum[i]=sum[i-1]+a[i];
	long long int ans=0;
	for(l=2;l<=n;l++)
	{
		for(i=0;i<n-l+1;i++)
		{
			j=i+l-1;
			dp[i][j]=inf;
			for(k=i;k<j;k++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
			}
			dp[i][j]+=sum[j];
			if(i)
				dp[i][j]-=sum[i-1];
		}
	}
	cout<<dp[0][n-1]<<endl;
	return 0;
}