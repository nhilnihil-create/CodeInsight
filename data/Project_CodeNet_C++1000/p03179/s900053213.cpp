//by (111110101)2
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<utility>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstdio>
using namespace std;
const long long md=1e9+7;
long long n,dp[3030][3030],sum[3030],ans;
string s;
int main()
{
	cin>>n>>s;
	dp[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		sum[0]=dp[i-1][0];
		for(int j=1;j<=n;j++)
		{
			sum[j]=sum[j-1]+dp[i-1][j];
			sum[j]%=md;
		}
		for(int j=1;j<=i;j++)
		{
			if(s[i-2]=='<')
			{
				dp[i][j]=sum[j-1];
			}
			else
			{
				dp[i][j]=(sum[i]-sum[j-1]+md)%md;
			}
		}
	}/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<dp[i][j]<<' ';
		}
		cout<<endl;
	}*/
	for(int i=1;i<=n;i++)
	{
		ans+=dp[n][i];
		ans%=md;
	}
	cout<<ans<<endl;
	return 0;
}