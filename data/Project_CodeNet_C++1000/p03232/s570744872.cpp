#include <iostream>
#define ll long long
using namespace std;

ll A[100010], sum[100010], mod=1000000007;

ll modpow(ll a, ll b, ll m){
    ll res=1, p=0, now=a;
    b %= (m-1);
    for(int i=0; b>p; ++i){
        if(b&((ll) 1<<i)){
            res=(res*now)%m;
            p |= ((ll) 1<<i);
        }
        now=(now*now)%mod;
    }
    return res;
}
ll modinv(ll a, ll m){
    return modpow(a, m-2, m);
}
ll moddiv(ll a, ll b, ll m){
    return (a*modinv(b, m))%m;
}

int main() {
	ll N;
	cin >> N;
	for(ll i=0; i<N; ++i) cin >> A[i];
	sum[0]=0;
	for(ll i=0; i<N; ++i) sum[i+1]=(sum[i]+A[i])%mod;
	ll frac=1, ans=0;
	for(ll i=1; i<=N; ++i) frac=(frac*i)%mod;
	ll now=0;
	for(ll i=1; i<=N-2; ++i){
		now=(now+mod+sum[N-i]-sum[i])%mod;
		ans=(ans+(now*moddiv(frac, ((i+2)*(i+1)/2)%mod, mod))%mod)%mod;
	}
	ans=(ans+(sum[N]*frac)%mod)%mod;
	for(ll i=1; i<N; ++i){
		ans=(ans+(((sum[i]+sum[N]-sum[N-i]+mod)%mod)*moddiv(frac, i+1, mod))%mod)%mod;
	}
	cout << ans << endl;
	return 0;
}
