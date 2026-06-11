#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100010
#define mod 1000000007
int ans,sum[N],n;
int qpow(int x,int y)
	{int tmp=1;while(y) {if(y&1) tmp=1ll*tmp*x%mod;y>>=1,x=1ll*x*x%mod;}return tmp;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) sum[i]=(sum[i-1]+qpow(i+1,mod-2))%mod;
	for(int i=1,x;i<=n;i++) scanf("%d",&x),(ans+=1ll*(sum[i-1]+sum[n-i])%mod*x%mod)%=mod,(ans+=x)%=mod;
	for(int i=1;i<=n;i++) ans=1ll*ans*i%mod;
	printf("%d\n",ans);
}