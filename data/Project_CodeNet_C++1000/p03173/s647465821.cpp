#include<iostream>
#include<cstring>
using namespace std;
long long a[401];
long long dp[401][401],h[401][401];
int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	memset(dp,0x3f,sizeof(dp));
	for(int len=1;len<=n;len++)
		for(int i=1;i<=n;i++)
		{
			int j=i+len-1;
			if(j>n)continue;
			if(i==j)dp[i][j]=0;
			h[i][j]=h[i][j-1]+a[j];
			for(int k=i;k<j;k++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+h[i][k]+h[k+1][j]);
		}
	cout<<dp[1][n];
	return 0;
}