#include<cstdio>
#include<algorithm>
using namespace std;
int gi(){
	int x=0,w=1;char ch=getchar();
	while ((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if (ch=='-') w=0,ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return w?x:-x;
}
const int N = 1e5+5;
const int mod = 1e9+7;
int n,inv[N],ans;
int main(){
	n=gi();inv[1]=1;
	for (int i=2;i<=n;++i) inv[i]=1ll*inv[mod%i]*(mod-mod/i)%mod;
	for (int i=2;i<=n;++i) inv[i]=(inv[i]+inv[i-1])%mod;
	for (int i=1;i<=n;++i) ans=(ans+1ll*gi()*(inv[i]+inv[n-i+1]-1))%mod;
	for (int i=1;i<=n;++i) ans=1ll*ans*i%mod;
	printf("%d\n",ans);return 0;
}
