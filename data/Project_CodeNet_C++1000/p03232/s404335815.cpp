#include<cstdio>
#include<algorithm>
#define rep(i,s,t) for(register int i=s;i<=t;++i)
using namespace std;
const int N=1e6+11,mod=1e9+7;
int n,ans;
int a[N],inv[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)
		scanf("%d",a+i);
	inv[1]=1;
	rep(i,2,n)
		inv[i]=mod-1ll*mod/i*inv[mod%i]%mod;
	rep(i,2,n)
		inv[i]=(inv[i]+inv[i-1])%mod;
	rep(i,1,n)
		ans=(ans+1ll*(inv[i]+inv[n-i+1]-1)*a[i])%mod;
	rep(i,1,n)
		ans=1ll*ans*i%mod;
	ans=(ans+mod)%mod;
	printf("%d\n",ans);
	return 0;
}