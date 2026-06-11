#include<iostream>
using namespace std;
const int MAXN=3000+10;
const int mod=1000000007;
int dp[MAXN][MAXN];
long long n,ans;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	cin>>s;
	s=' '+s;
	s=' '+s;
	dp[1][1]=1;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='<')
		{
			for(int k=2;k<=i;k++)
			{
				dp[i][k]=dp[i-1][k-1]+dp[i][k-1];
				dp[i][k]%=mod;
			}
		}
		if(s[i]=='>')
		{
			for(int k=i;k>=0;k--)
			{
				dp[i][k]=dp[i][k+1]+dp[i-1][k];
				dp[i][k]%=mod;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans+=dp[n][i];
		ans%=mod;
	}
	cout<<ans;
	return 0;
}