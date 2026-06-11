#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define lowbit(x) (x)&(-x)
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define per(i,a,b) for (int i=a;i>=b;i--)
#define maxd (ll)10000000000007
typedef long long ll;
const int N=100000;
const double pi=acos(-1.0);
int n,a,b,num[5050];
ll dp[5050][5050];

int read()
{
	int x=0,f=1;char ch=getchar();
	while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
	while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
	return x*f;
}

int main()
{
	n=read();a=read();b=read();
	rep(i,1,n) num[i]=read();
	rep(i,0,n)
		rep(j,0,n) dp[i][j]=maxd;
	dp[0][0]=0;
	rep(i,1,n)
	{
		rep(j,0,n)
		{
			if (dp[i-1][j]==maxd) continue;
			if (num[i]>j)
			{
				dp[i][j]=min(dp[i][j],dp[i-1][j]+a);
				dp[i][num[i]]=min(dp[i][num[i]],dp[i-1][j]);
			}
			else 
			{
				dp[i][j]=min(dp[i][j],dp[i-1][j]+b);
			}
		}
	}
	ll ans=maxd;
	rep(i,1,n) ans=min(ans,dp[n][i]);
	printf("%lld",ans);
	return 0;
}