#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int _=1e5+5;
const int mod=1e9+7;
#define ll long long
inline int read()
{
	char ch='!';int z=1,num=0;
	while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch=='-')z=-1,ch=getchar();
	while(ch<='9'&&ch>='0')num=(num<<3)+(num<<1)+ch-'0',ch=getchar();
	return z*num;
}
ll n,a[_],jjc[_];
ll ksm(ll a,ll b){ll r=1;for(;b;b>>=1,a=a*a%mod)if(b&1)r=a*r%mod;return r;}
int main()
{
	n=read();ll tmp=1;
	for(int i=1;i<=n;++i)
		a[i]=read(),tmp=tmp*i%mod;
	for(int i=1;i<=n;++i)
		jjc[i]=(jjc[i-1]+tmp*ksm(i,mod-2))%mod;
	ll Ans=0;
	for(int i=1;i<=n;++i)
		(Ans+=(jjc[i]+jjc[n-i+1]-tmp)%mod*a[i]%mod)%=mod;
	(Ans+=mod)%=mod;
	printf("%lld\n",Ans);
	return 0;
}