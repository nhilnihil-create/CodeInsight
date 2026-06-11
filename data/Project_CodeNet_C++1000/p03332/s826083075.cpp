#include<cstdio>
using namespace std;

const int mod=998244353,maxn=3e5+7;
int a,b,n;
long long k;
long long x,y,ans;

long long c[maxn]={1},inv[maxn]={1},fac[maxn]={1};

long long poww(int x,int y)
{
	long long ans=1,base=x;
	while(y){
		if(y&1)ans=(ans*base)%mod;
		base=(base*base)%mod;
		y>>=1;
	}
	return ans;
}

void pre()
{
	fac[0]=1,fac[1]=1;
    for(int i=2;i<=n+1;i++) fac[i]=fac[i-1]*i%mod;
    inv[n+1]=poww(fac[n+1],mod-2);
    for(int i=n;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}

long long get_c(int x)
{
	return ((1ll*fac[n]*inv[n-x])%mod*inv[x])%mod;
}

int main()
{
//	freopen("a.txt","r",stdin);
	scanf("%d %d %d %lld",&n,&a,&b,&k);
	if(k==0){printf("1"); return 0;}
	pre();
	for(x=1;x<=n;++x){
		if((k-x*a)%b)continue;
		y=(k-a*x)/b;
		if(y>n||y<0)continue;
		ans+=get_c(x)*get_c(y);
		ans%=mod;
	}
	printf("%lld",ans%mod);
	return 0;
}