#include<cstdio>
#define N 5005
#define inf 0x3f3f3f3f3f3f3f3fll
inline long long min(long long x,long long y){return x<y?x:y;}
inline long long max(long long x,long long y){return x<y?y:x;}
int a[N],b[N],i,j,n,o,p;long long f[2][N],x;
int main()
{
	scanf("%d%d%d",&n,&o,&p),x=f[1][0]=inf;
	for(i=1;i<=n;i++)scanf("%d",a+i),f[0][b[a[i]]=i]=f[1][i]=inf;
	for(i=1;i<=n;i++)for(j=0;j<=n;f[i&1^1][j++]=inf)
	if(a[i]>j)f[i&1][a[i]]=min(f[i&1][a[i]],f[i&1^1][j]),f[i&1][j]=min(f[i&1][j],f[i&1^1][j]+o);
	else f[i&1][j]=min(f[i&1][j],f[i&1^1][j]+p);
	for(i=0;i<=n;i++)x=min(x,f[n&1][i]);
	return 0*printf("%lld\n",x);
}