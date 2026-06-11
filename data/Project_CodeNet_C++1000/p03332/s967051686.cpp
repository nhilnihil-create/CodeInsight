#include<cstdio>

typedef long long ll;
const int maxn = 300010;
const ll mod = 998244353;

ll n,a,b,k;
ll fac[maxn],inv[maxn];

ll qpow_mod(ll x,ll n){
	int s = 1;
	while(n){
		if(n&1) s=s*x % mod;
		x = x*x % mod;
		n >>= 1;
	}
	return s;
}
void csh(){
	fac[0] = 1;
	for(int i = 1; i<=300000; i++) fac[i] = fac[i-1]*i % mod;
	inv[300000] = qpow_mod(fac[300000],mod-2);
	for(int i = 300000; i>0; i--) inv[i-1] = inv[i]*i % mod;
}
ll C(ll n, ll a){
	return fac[n]*inv[a] %mod * inv[n-a] %mod; 
}
int main()
{
	csh();
	ll ans = 0;
	scanf("%lld%lld%lld%lld",&n,&a,&b,&k);
	for(int i = 0; i<=n; i++){
		if((k - a*i)%b != 0 || (k - a*i)/b > n || (k - a*i)<0)continue;
		ans = (ans + C(n,i)*C(n,(k-a*i)/b))%mod;
	}
	printf("%lld\n",ans);
	return 0;
}