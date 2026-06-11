#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

ll fac[maxn],inv[maxn],n,k,a,b,c,ans;
const ll mod=998244353;

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

inline ll C(ll N,ll M){return (fac[N]*inv[M]%mod)*inv[N-M]%mod;}

int main()
{
	fac[0]=1; inv[0]=1;
	rep(i,1,(maxn-5)) fac[i]=(fac[i-1]*i)%mod;
	rep(i,1,(maxn-5)) inv[i]=pw(fac[i],mod-2);
	cin>>n>>a>>b>>k;
	for(ll i=0;i<=n;i++)
	{
		ll res=k-i*a; if(res<0) break;
		if(res%b!=0||res/b>n) continue;
		ll x=i,y=res/b; ans=(ans+C(n,x)*C(n,y))%mod;
	}
	cout<<ans<<endl;
	return 0;
}