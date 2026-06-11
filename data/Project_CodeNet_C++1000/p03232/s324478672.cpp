#include<cstdio>
using namespace std;
const int md=1e9+7;
int n,fac[100010],ifac[100010],sum[100010],x,ans;
int read() {
	int tmp=0, fh=1; char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') fh=-1; c=getchar();}
	while (c>='0'&&c<='9') tmp=tmp*10+c-48, c=getchar();
	return tmp*fh;
}
int main() {
	n=read(); fac[0]=1; ifac[n]=1;
	for (int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%md;
	for (int i=n-1;i;i--) ifac[i]=1ll*ifac[i+1]*(i+1)%md;
	for (int i=1;i<=n;i++) sum[i]=(sum[i-1]+1ll*fac[i-1]*ifac[i])%md;
	for (int i=1;i<=n;i++)
		ans=(ans+1ll*read()*((sum[i]-sum[1]+md)%md+sum[n-i+1])%md)%md;
	printf("%d\n",ans);
}