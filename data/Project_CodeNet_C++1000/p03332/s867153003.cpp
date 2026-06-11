// FUCKED UP FUCKED UP FUCKED UP FUCKED UP FUCKED UP
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2,no-stack-protector,unroll-loops,fast-math")

#define F first
#define S second
#define pb push_back
#define SZ(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define MP make_pair

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=3e5+10, maxm=5e4+10, lg=21, mod=998244353, inf=1e18;

ll n,A,B,K,fac[maxn],inv[maxn];
ll pwm(ll a,ll b){if(b==0)return 1;if(b%2)return a*pwm(a,b-1)%mod;ll ret=pwm(a,b/2);return ret*ret%mod;}
ll C(ll n,ll r){return fac[n]*inv[r]%mod*inv[n-r]%mod;}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	fac[0]=inv[0]=1; for(int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%mod, inv[i]=pwm(fac[i],mod-2);
	cin>>n>>A>>B>>K;
	ll ans=0;
	for(int i=0;i<=n;i++)if(K-i*A>=0 && (K-i*A)%B==0){
		ll cc=(K-i*A)/B;
		if(cc>n) continue;
		ans+=C(n,i)*C(n,cc)%mod, ans%=mod;
	}
	cout<<ans;
	
	return 0;
}



 
