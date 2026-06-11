#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read()
{
	ll out=0,fh=1;
	char jp=getchar();
	while ((jp>'9'||jp<'0')&&jp!='-')
		jp=getchar();
	if (jp=='-')
		{
			fh=-1;
			jp=getchar();
		}
	while (jp>='0'&&jp<='9')
		{
			out=out*10+jp-'0';
			jp=getchar();
		}
	return out*fh;
}
const int MAXN=1e5+10;
const ll P=1e9+7;
ll n,a[MAXN];
ll add(ll a,ll b)
{
	return (a+b) % P;
}
ll mul(ll a,ll b)
{
	return a * b % P;
}
ll fpow(ll a,ll b)
{
	ll res=1;
	while(b)
		{
			if(b&1)
				res=mul(res,a);
			a=mul(a,a);
			b>>=1;
		}
	return res;
}
ll getinv(ll x)
{
	return fpow(x,P-2);
}
ll inv[MAXN],pre[MAXN];
ll fac[MAXN];
int main()
{
  	//freopen(".in","r",stdin);
  	//freopen(".out","w",stdout);
  	n=read();
  	for(int i=1;i<=n;++i)
  		a[i]=read();
  	for(int i=1;i<=n;++i)
  		inv[i]=getinv(i),pre[i]=add(pre[i-1],inv[i]);
  	ll ans=0;
  	for(int i=1;i<=n;++i)
  		ans=add(ans,mul(a[i],pre[i]-1)),ans=add(ans,mul(a[i],pre[n-i+1]));
  	fac[0]=1;
  	for(int i=1;i<=n;++i)
  		fac[i]=mul(fac[i-1],i);
  	ans=mul(ans,fac[n]);
  	cout<<ans;
	return 0;
}
