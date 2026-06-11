#include<iostream>
using namespace std;
const int mod=1e9+7;
int a[101];
int dp[100001][101];
int qzh[100001][101];
int main()
{
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	qzh[0][0]=dp[0][0]=1;
	for(int i=1;i<=k;i++)
		qzh[i][0]=qzh[i-1][0]+dp[i][0];
	for(int i=1;i<=n;i++)
		qzh[0][i]=dp[0][i]=1;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=(qzh[i][j-1]-((i-a[j]>0)?qzh[i-a[j]-1][j-1]:0))%mod;
			qzh[i][j]=(qzh[i-1][j]+dp[i][j])%mod;
		}
	cout<<(dp[k][n]+mod)%mod;
	return 0;
}