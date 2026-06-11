#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int N=1e5+5,MOD=1e9+7;
int ans,n,x;
int fac[N],rev[N],f[N],s[N];
int pw(int x,int y){
	int s=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)s=1ll*s*x%MOD;
	return s;
}
int main(){
	scanf("%d",&n);
	fac[0]=1;rep(i,n)fac[i]=1ll*fac[i-1]*i%MOD;
	rev[n]=pw(fac[n],MOD-2);
	for(int i=n-1;~i;--i)rev[i]=1ll*rev[i+1]*(i+1)%MOD;
	rep(i,n)f[i]=(1ll*f[i-1]*i+fac[i-1])%MOD;
	rep(i,n)s[i]=(1ll*f[i]*rev[i]+1ll*f[n-i+1]*rev[n-i+1]+MOD-1)%MOD*fac[n]%MOD;
	rep(i,n)scanf("%d",&x),ans=(ans+1ll*x*s[i])%MOD;
	printf("%d\n",ans);
}