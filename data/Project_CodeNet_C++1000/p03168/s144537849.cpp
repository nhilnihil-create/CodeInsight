#include<iostream>
#include<cstdio>
using namespace std;
double p[3000];
double dp[3000][6000];
int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	dp[0][3000]=1;
	for(int i=1;i<=n;i++)
		for(int j=-i+3000;j<=i+3000;j++)
			dp[i][j]=dp[i-1][j-1]*p[i]+dp[i-1][j+1]*(1-p[i]);
	double ans=0;
	for(int i=3001;i<=3000+n;i++)
		ans+=dp[n][i];
	printf("%.10lf",ans);
}