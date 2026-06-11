#include <iostream>
#define ll long long
using namespace std;

ll mod=998244353;
const int arm=310000;
ll fac[arm], finv[arm], inv[arm];
void COMinit(ll m){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for (int i=2; i<arm; ++i){
        fac[i]=(fac[i-1]*i)%m;
        inv[i]=m-(inv[m%i]*(m/i))%m;
        finv[i]=(finv[i-1]*inv[i])%m;
    }
}
ll COM(ll n, ll k, ll m){
    if(n<k) return 0;
    if(n<0 || k<0) return 0;
    return (fac[n]*((finv[k]*finv[n-k])%m))%m;
}


int main() {
	ll N, A, B, K;
	cin >> N >> A >> B >> K;
	ll ans=0;
	COMinit(mod);
	for(ll i=0; i<=N && i*A<=K; ++i){
		ll j=(K-i*A)/B;
		if(i*A+j*B==K && j<=N){
			ans=(ans+(COM(N, i, mod)*COM(N, j, mod))%mod)%mod;
		}
	}
	cout << ans << endl;
	return 0;
}