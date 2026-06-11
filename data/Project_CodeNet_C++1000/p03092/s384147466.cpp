#include <cstdio>
#include <algorithm>
using namespace std;
#define N 5010
#define inf 1000000000000000000ll
int n,A,B;long long f[N][N],ans;
int main()
{
	scanf("%d%d%d",&n,&A,&B);
	for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) f[i][j]=inf; f[0][0]=0;
	for(int i=1,x;i<=n;i++)
	{
		scanf("%d",&x);
		for(int j=0;j<=n;j++)
			if(x>j) f[i][j]=min(f[i][j],f[i-1][j]+A),f[i][x]=min(f[i][x],f[i-1][j]);
			else f[i][j]=min(f[i][j],f[i-1][j]+B);
	}
	ans=inf;
	for(int i=0;i<=n;i++) ans=min(ans,f[n][i]);
	printf("%lld\n",ans);
}