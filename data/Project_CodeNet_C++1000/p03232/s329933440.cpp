#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

typedef long long LL;

const int maxn=1e5+5;
const LL mo=1e9+7;

int n;
LL a[maxn],inv[maxn];

LL Pow(LL x,LL y)
{
	LL re=1;
	for(; y; y>>=1, x=x*x%mo) if (y&1) re=re*x%mo;
	return re;
}

int main()
{
	scanf("%d",&n);
	fo(i,1,n) scanf("%lld",&a[i]);
	
	LL fac=1;
	fo(i,1,n) (fac*=i)%=mo, inv[i]=(inv[i-1]+Pow(i,mo-2))%mo;
	
	LL ans=0;
	fo(i,1,n) (ans+=fac*(inv[i]+inv[n-i+1]-1)%mo*a[i])%=mo;
	
	printf("%lld\n",(ans%mo+mo)%mo);
}