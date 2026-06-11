#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll md = 1000000007;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;
vl p, fac(2, 1), ifac(2, 1);

ll ad(ll a, ll b, ll mod = md) {
    return (a%mod + b%mod + mod) % mod;
}

ll ml(ll a, ll b, ll mod = md) {
    return ( (a%mod) * (b%mod) ) % mod;
}

ll pw(ll x, ll n, ll mod = md) {
    ll res = 1;
    x %= mod;
    while (n) {
        if (n & 1)  res = (res*x)%mod;
        n = (n >> 1);
        x = (x*x)%mod;
    }
    return res;
}

int mu(ll n) {
	int c = 1, pn = p.size();
	for(int i = 0; i < pn && p[i] * p[i] <= n; i++) {
		if(n%p[i] == 0) c = -c, n /= p[i];
		if(n%p[i] == 0) return 0;
	}
	if(n > 1) return -c;
	return c;
}

void sieveMU(ll n, vl &mu) {
    vl factor(n+1, 0);
    for(int i = 2; i * i <= n; i++) {
        if(!factor[i]) {
            for(int j = i * i; j <= n; j += i) factor[j] = i;
        }
    }
    mu[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(!factor[i]) {
            mu[i] = -1;
            continue;
        }
        if((i/factor[i])%factor[i] == 0) {
            mu[i] = 0;
        } else {
            mu[i] = (-1)*mu[i/factor[i]];
        }
    }
}

void cachefact(ll lim, ll mod = md) {
    for(int i = 2; i <= lim; i++) {
        ifac.push_back((ifac[mod%i] * (mod - mod/i) % mod)%mod);
    }
    for(ll i = 2; i <= lim; i++) {
        fac.push_back((fac[i-1] * i)%mod);
        ifac[i] = (ifac[i-1] * ifac[i])%mod;
    }
}

ll C(ll n, ll r) {
    if(n < r || r < 0) return 0;
    ll ans = 1;
    for(int i = 0; i < r; i++) ans = ml(ans, n - i);
    return ml(ans, ifac[r]);
}

ll P(int n, int r) {
    if(n < r || r < 0) return 0;
    return ml(fac[n], ifac[n-r]);
}

void sieve(ll n) {
    vector<bool> prime(n+1, true);
    for(int i = 2; i*i <= n; i++) {
        if(prime[i]) {
            for(int j = i*i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    p.push_back(2);
    for(int i = 3; i <= n; i += 2) {
        if(prime[i]) p.push_back(i);
    }
}

ll PIE(ll n, ll k, ll f, ll mod = md) {
	if(f < 0 || k < 0 || n <= 0) return 0;
	ll ans = 0, l = min(n, k/(f+1));
	for(int i = 0; i <= l; i++) {
		ans = ad(ans, (i&1 ? -1 : 1) * ml(C(n, i), C(n - 1 + k - (f+1) * i, k - (f+1) * i)));
	}
	return ans;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vl a(n);
    vvl dp(n+1, vl(k+1, 0));
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for(int i = 0; i <= a[0]; i++) {
    	dp[0][i] = 1;
    }
    for(int i = 1; i < n; i++) {
    	vl pref(k+1, 0);
    	for(int j = 0; j <= k; j++) { 
    		if(j > a[i]) {
    			pref[j] = ad(dp[i-1][j], +(j >= 1 ? pref[j-1] : 0));
    			dp[i][j] = ad(pref[j], -pref[j - a[i] - 1]);
    		} else {
    			pref[j] = ( dp[i-1][j] + (j >= 1 ? pref[j-1] : 0) ) % md;
    			dp[i][j] = pref[j];
    		}
    	}
    }
    cout << dp[n-1][k]%md << "\n";
    return 0;
}