#include<cstdio>
#include<algorithm>
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
typedef long long ll;
using namespace std;

const int N=100010,mod=1e9+7;
int n,h[N],x,ans,r=1;

int ksm(int a,int b){
	int res=1;
	for (; b; a=1ll*a*a%mod,b>>=1)
		if (b & 1) res=1ll*res*a%mod;
	return res;
}

int main(){
	scanf("%d",&n);
	rep(i,1,n) h[i]=(h[i-1]+ksm(i,mod-2))%mod;
	rep(i,1,n) scanf("%d",&x),ans=(ans+1ll*x*(1ll*h[i]+h[n-i+1]-1+mod)%mod)%mod,r=1ll*r*i%mod;
	printf("%lld\n",1ll*ans*r%mod);
	return 0;
}