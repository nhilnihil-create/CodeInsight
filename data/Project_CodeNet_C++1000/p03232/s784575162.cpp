#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll fac[maxn],inv[maxn],n,k,p[maxn],a[maxn];
const ll mod=1000000007;

inline ll pw(ll a,ll b)
{
	ll ans=1,base=a;
	while(b)
	{
		if(b&1) ans=(ans*base)%mod;
		base=(base*base)%mod; b>>=1;
	}
	return ans;
}

int main()
{
	fac[0]=1; inv[0]=1;
	rep(i,1,(maxn-5)) fac[i]=(fac[i-1]*i)%mod;
	rep(i,1,(maxn-5)) inv[i]=pw(i,mod-2);
	n=read(); rep(i,1,n) a[i]=read(); inv[0]=fac[n];
	rep(i,1,n) inv[i]=(inv[i]*fac[n])%mod,p[i]=(p[i-1]+inv[i])%mod;
	ll ans=0;
	rep(i,1,n) ans+=(a[i]*(p[i]+p[n-i+1]-p[1]+mod)%mod)%mod,ans%=mod;
	cout<<ans<<endl;
	return 0;
}