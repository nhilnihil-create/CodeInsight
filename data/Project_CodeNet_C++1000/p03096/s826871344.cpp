#include<cstdio>
#define RI register int
#define CI const int&
using namespace std;
const int N=200005,mod=1e9+7;
int n,x,pre[N],f[N];
inline void inc(int& x,CI y)
{
	if ((x+=y)>=mod) x-=mod;
}
int main()
{
	RI i,j; for (scanf("%d",&n),f[0]=i=1;i<=n;pre[x]=i++)
	if (scanf("%d",&x),f[i]=f[i-1],pre[x]&&pre[x]!=i-1) inc(f[i],f[pre[x]]);
	return printf("%d",f[n]),0;
}