#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#define N 5001
#include<bitset>
#include<deque>
#include<cstdlib>
#include<set>
#include<ctime>
#define ll long long
#define mp make_pair
using namespace std;
ll read()
{
	ll x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}
int n,pos[N],A,B;
ll dp[N][N];
int main()
{
	n=read(),A=read(),B=read();
	memset(dp,20,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;++i)
	{
		int x=read();
		pos[x]=i;
	}
	for(int i=1;i<=n;++i)
	{
		ll mn=dp[i-1][0];
		for(int j=0;j<=n;++j)
		{
			if(pos[i]==j) dp[i][j]=mn;
			mn=min(mn,dp[i-1][j]);
			dp[i][j]=min(dp[i][j],mn+(j<pos[i]?B:A));
		}
	}
	ll ans=1e18;
	for(int i=1;i<=n;++i) ans=min(ans,dp[n][i]);
	cout<<ans<<'\n';
	return 0;
 }
