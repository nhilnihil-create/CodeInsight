#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define LL long long 
#define mod 998244353
using namespace std;
LL f[300005];
LL ans;
LL n,a,b,k;
LL quick_pow(LL a,LL b)
{
	LL ret=1;
	while(b)
	{
		ret=ret*(b&1?a:1)%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
LL C(LL n,LL m)
{
	if(m>n)return 0;
	return f[n]*quick_pow(f[m],mod-2)%mod*quick_pow(f[n-m],mod-2)%mod;
}
void Pre()
{
	f[0]=f[1]=1;
	for(int i=2;i<=300001;++i)
	f[i]=f[i-1]*i%mod;
}
int main()
{
ios::sync_with_stdio(false);
	cin>>n>>a>>b>>k;
	Pre();
for(int i=0;i<=n;++i)
{
	if(i*a>k)break;
	LL bule=(k-i*a)/b;
	if((k-i*a)%b==0&&bule<=n)
	{
		ans+=C(n,i)*C(n,bule)%mod;
		ans%=mod;
	}
}
cout<<ans<<endl;
return 0;
} 