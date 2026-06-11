#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
ll dp[1<<16],w[1<<16];int n,a[101][101];
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)scanf("%d",&a[i][j]);
	for(int i=1;i<(1<<n);++i){ll ans=0;int k=log2(i&-i);for(int j=1;j<=n;++j)(i&(1<<j-1))&&(ans+=a[k+1][j]);w[i]=w[i&(i-1)]+ans;}
	memset(dp,-0x3f,sizeof(dp));dp[0]=0;
	for(int i=0;i<(1<<n);++i)for(int x=(~i)&((1<<n)-1);x;x=(x-1)&(~i))dp[i|x]=max(dp[i|x],dp[i]+w[x]);
	printf("%lld\n",dp[(1<<n)-1]);return 0;
}