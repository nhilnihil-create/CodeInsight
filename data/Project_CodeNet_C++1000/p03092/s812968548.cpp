#include<cstdio>
#include<iostream>
#define RI register int
#define CI const int&
using namespace std;
const int N=5005;
const long long INF=1e18;
int n,a,b,x; long long f[N][N],ans=INF;
int main()
{
	RI i,j; for (scanf("%d%d%d",&n,&a,&b),i=1;i<=n;++i)
	for (j=1;j<=n;++j) f[i][j]=INF; for (i=1;i<=n;++i)
	for (scanf("%d",&x),j=1;j<=n;++j)
	if (x<j) f[i][j]=min(f[i][j],f[i-1][j]+b); else
	f[i][x]=min(f[i][x],f[i-1][j]),f[i][j]=min(f[i][j],f[i-1][j]+a);
	for (i=1;i<=n;++i) ans=min(ans,f[n][i]);
	return printf("%lld",ans),0;
}