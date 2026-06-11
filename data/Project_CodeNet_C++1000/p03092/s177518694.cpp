#include <bits/stdc++.h>
#define ri register
#define int long long
using namespace std; const int N=5010;
inline int read()
{
    int s=0,w=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar(); return s*w;
}
int n,A,B,val[N];
int dp[N][N],p[N];
signed main()
{
	n=read(), A=read(), B=read();
	for(ri int i=1;i<=n;i++) {int x=read(); p[x]=i; }
	for(ri int i=1;i<=n;i++) for(ri int j=0;j<=n;j++) dp[i][j]=LONG_LONG_MAX/2;
	for(ri int i=1;i<=n;i++)
	{
		for(ri int j=0;j<=n;j++)
		{
			if(p[i]==j)
			{
				dp[i][j]=min(dp[i-1][j-1],dp[i][j]);
				continue;
			}
			dp[i][j]=min(dp[i][j],dp[i-1][j]+(j<p[i]?B:A));
		}
		for(ri int j=1;j<=n;j++) dp[i][j]=min(dp[i][j],dp[i][j-1]);
	}
	printf("%lld\n",dp[n][n]);
    return 0;
}