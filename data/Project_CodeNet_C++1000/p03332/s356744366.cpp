#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back

#define y0 pmt
#define y1 pmtpmt
#define x0 pmtQAQ
#define x1 pmtQwQ

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int > vi;
typedef pair<int ,int > pii;
typedef vector<pii> vii;
const int inf=0x3f3f3f3f, maxn=3000007;
const ll mod=998244353;
const ll linf=0x3f3f3f3f3f3f3f3fLL;
const ll P=998244353;
ll n,A,B,k;
ll f[maxn],g[maxn],d[maxn];
ll qpow(ll a,ll b){
	ll rt=1;
	while(b){
		if(b&1)rt=(rt*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return rt;
}

ll C(ll n,ll m){
	if(n<m)return 0;
	return (f[n]*g[m]%mod*g[n-m]%mod);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	f[0]=1;
	for(int i=1;i<=3000000;i++)f[i]=f[i-1]*i%mod;
	g[3000000]=qpow(f[3000000],mod-2);
	for(int i=3000000;i>=1;i--)g[i-1]=g[i]*i%mod;
	scanf("%lld%lld%lld%lld",&n,&A,&B,&k);
	ll ans=0;
	for(ll i=0;i<=n;i++){
		if((k-i*A)%B!=0)continue;
		ll j=(k-i*A)/B;
		(ans+=C(n,i)*C(n,j)%mod)%mod;
	}
	printf("%lld",ans%mod);
	return 0;
}
