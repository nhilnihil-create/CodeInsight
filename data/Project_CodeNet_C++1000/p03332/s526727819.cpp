#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;
const int N = 3e5;

ll dmod(ll x){
	return x%MOD;
}

ll fe(ll x, ll p){
	if(p==0) return 1ll;
	if(p==1) return x;
	ll ret = fe(x,p/2);
	ret = dmod(ret*ret);
	if(p&1) ret = dmod(ret*x);
	return ret;
}

ll fakto[N+5];

void pre(){
	fakto[0] = 1ll;
	for(int i=1;i<=N;i++){
		fakto[i] = dmod(fakto[i-1] * (ll)i);
	}
	return;
}

ll nCr(ll n, ll r){
	ll inv = dmod(fakto[r] * fakto[n-r]);
	inv = fe(inv,MOD-2);
	return dmod(inv*fakto[n]);
}

int n;
ll a,b,k;


int main(){
	pre();
	scanf("%d",&n);
	scanf("%lld%lld%lld",&a,&b,&k);
	ll ans = 0ll;
	for(int i=0;i<=n;i++){
		ll dk = k - a*(ll)i;
		if(dk < 0) break;
		if(dk%b != 0) continue;
		ll bagi = dk/b;
		if(bagi > n) continue;
		ll ret = nCr(n,i);
		ret = dmod(ret*nCr(n,bagi));
		ans = dmod(ans+ret);
	}
	printf("%lld\n",ans);
	return 0;
}
