#include<bits/stdc++.h>

typedef long long ll;
 
using namespace std;

const ll mod = 998244353; 
ll n; 
ll a, b; 
ll k, g, f, x, y, bruh;
ll fakt[300001];
ll mul(ll x, ll y) {
	x *= y;
	return x%mod;
}


ll pot(ll z, ll u) {
	if(u == 0) return 1;
	if(u == 1) return z;
	if(u%2 == 0) {
		ll x = pot(z, u/2);
		return mul(x, x);
	}
	return mul(pot(z, u - 1), z);
}

ll dvd(ll z, ll u) {
	u = pot(u, mod - 2);
	z *= u;
	return z%mod;
}

ll pov(ll z) {
	return dvd(fakt[n], mul(fakt[z], fakt[n - z]))%mod;
}

int main() {
	cin >> n >> a >> b >> k;
	fakt[0] = 1;
	for(int  i = 1; i < 300001; i++) {
		fakt[i] = mul(fakt[i - 1], i);
	}
	for(int i = 0; i <= n; i++) {
		if((k - (a * i))%b == 0 && (k - (a * i))/b <= n) {
			bruh = (k - (a * i))/b;
				if(bruh >= 0) {
					g += mul(pov(i), pov(bruh));
				}
		}
	}
	cout << g%mod;
}
