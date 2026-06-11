#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define mod 998244353

vector<ll> v(3*(ll)(1e5+1),0);
vector<ll> v_inv(3*(ll)(1e5+1),0);

ll pmod(ll n, ll p){
	ll m=n%mod;
	if(p==0) return 1;
	ll ans=pmod((m*m)%mod, p/2)%mod;
	if(p%2==1) ans=ans*m%mod;
	return ans;
}

void factorial(ll n){
	v[0]=1;
	for(ll i=1; i<=n; i++){
		v[i]=v[i-1]*i%mod;
	}
	return;
}

void factorial_inv(ll n){
	for(ll i=0; i<=n; i++){
		v_inv[i]=pmod(v[i],mod-2);
	}
}

ll binom(ll n, ll k){
	if(n<k || n<0 || k<0) return 0;
	ll tmp=v_inv[k]*v_inv[n-k]%mod;
	return v[n]*tmp%mod;
}

int main(){
	ll n, a, b, k;
	cin >> n >> a >> b >> k;
	factorial(n);
	factorial_inv(n);

	ll ans=0;
	for(ll i=0; a*i<=k; i++){
		if((k-a*i)%b==0){
			ll j=(k-a*i)/b;
			ans+=binom(n, i)*binom(n, j)%mod;
			ans%=mod;
		}
	}
	cout << ans << endl;
	return 0;
}