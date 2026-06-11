#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 5000
#define LL long long
using namespace std;
int n,A,B,a[N+5];LL f[N+5][N+5];
int main()
{
	RI i,j;for(scanf("%d%d%d",&n,&A,&B),i=1;i<=n;++i) scanf("%d",a+i);
	for(memset(f,63,sizeof(f)),f[0][0]=0,i=1;i<=n;++i)
	{
		for(j=0;j^a[i];++j) f[i][j]=min(f[i][j],f[i-1][j]+A),f[i][a[i]]=min(f[i][a[i]],f[i-1][j]);
		for(j=a[i]+1;j<=n;++j) f[i][j]=min(f[i][j],f[i-1][j]+B);
	}
	LL ans=f[0][1];for(i=0;i<=n;++i) ans=min(ans,f[n][i]);return printf("%lld\n",ans),0;
}