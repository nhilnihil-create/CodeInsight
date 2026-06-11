#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
#define N 100050
int n;
ll C,f[N],g[N],s[N],sx[N],p[N],c[N],sc[N],f2[N],g2[N];
int main() {
	scanf("%d%lld",&n,&C);
	int i;
	ll ans=0;
	for(i=1;i<=n;i++) scanf("%lld%lld",&p[i],&c[i]),sx[i]=sx[i-1]+p[i],sc[i]=sc[i-1]+c[i];
	for(i=1;i<=n;i++) f[i]=sc[i]-p[i],g[i]=sc[n]-sc[i-1]-(C-p[i]),ans=max(ans,max(f[i],g[i]));
	for(i=1;i<=n;i++) f2[i]=max(f[i],f2[i-1]);
	for(i=n;i>=1;i--) g2[i]=max(g[i],g2[i+1]);
	for(i=1;i<=n;i++) ans=max(ans,f[i]+g2[i+1]-p[i]);
	for(i=1;i<=n;i++) ans=max(ans,g[i]+f2[i-1]-(C-p[i]));
	printf("%lld\n",ans);
}