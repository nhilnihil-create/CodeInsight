#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstring>
#define ll long long
using namespace std;
const int D=998244353,MAXN=300005;
ll n,a,b,k,x,y,ans;
ll ifac[MAXN],fac[MAXN];
ll power_(ll x,ll k)
{
	ll ret=1;
	while(k)
	{
		if(k&1) ret=(ret*x)%D;
		x=(x*x)%D;
		k>>=1;
	}
	return ret;
}
void first_()
{
	fac[0]=fac[1]=1;
	for(int i=2;i<=n;i++) fac[i]=(fac[i-1]*i)%D;
	ifac[n]=power_(fac[n],D-2);
	for(int i=n;i>=1;i--)
		ifac[i-1]=(ifac[i]*i)%D;
}
ll C(ll aa,ll bb)
{
	if(bb<aa) return 0;
	return (fac[bb]*ifac[aa]%D*ifac[bb-aa])%D;
}
int main()
{
	scanf("%lld%lld%lld%lld",&n,&a,&b,&k);
	first_();
	for(int i=0;;i++)
	{
		if(a*i>k) break;
		if((k-a*i)%b==0)
		{
			x=i;
			y=(k-a*i)/b;
			ans=(ans+C(x,n)*C(y,n)+D)%D;
		}
	}
	printf("%lld\n",ans);
	return 0;
}