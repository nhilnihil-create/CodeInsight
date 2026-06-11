#include<cstdio>
#define RI register int
#define CI const int&
using namespace std;
const int N=105;
int n,m; bool g[N][N];
int main()
{
	RI i,j; for (scanf("%d",&n),i=1;i<=n;++i)
	for (j=i+1;j<=n;++j) g[i][j]=1;
	for (i=1;i<n-i+!(n&1);++i) g[i][n-i+!(n&1)]=0;
	for (i=1;i<=n;++i) for (j=i+1;j<=n;++j) if (g[i][j]) ++m;
	for (printf("%d\n",m),i=1;i<=n;++i) for (j=i+1;j<=n;++j)
	if (g[i][j]) printf("%d %d\n",i,j); return 0;
}