#include <bits/stdc++.h>
#include <stdio.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)

typedef long long ll;
const int maxn = 2e5+10;
const int mod = 1e9+7;
const int inf = 0x3f3f3f3f;
using namespace std;

inline ll qpow(ll a,ll n) { ll res = 1 ; for(;n;n>>=1) {if( n&1 )res = (res*a)%mod; a = (a*a)%mod ; }return res;}
ll fac = 1,inv[maxn+10],a[maxn+10];
int main(int argc, char const *argv[])
{
	ll n,ans  = 0;
	scanf("%lld",&n);
	rep(i,1,n) { fac = (fac*i)%mod;	inv[i] = qpow(1ll*i,mod-2); } 
	rep(i,1,n) { inv[i] += (inv[i-1])%mod; scanf("%lld",&a[i]);}
	rep(i,1,n) { ans = (ans + (a[i]*(inv[i]+inv[n-i+1]-1)%mod)%mod)%mod; }
	printf("%lld\n", (fac*ans)%mod );
	return 0;
}