#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define rrep(i,n) RFOR(i,n,0)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9 + 7;

ll mod(ll a, ll b){
  a %= b;
  return a < 0 ? a + b : a;
}

ll powmod(ll a, ll b){
  if(b == 0) return 1;
  if(b & 1) {
    return a * powmod(a, b - 1) % MOD;
  } else {
    ll d = powmod(a, b / 2) % MOD;
    return d * d % MOD;
  }
}

ll sub(ll a, ll b){
  a %= MOD, b %= MOD;
  a -= b;
  return a < 0 ? a + MOD : a;
}


ll inv(ll a){
	return powmod(a, MOD - 2);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n;
	cin >> n;

	ll a[n];
	rep(i, n) cin >> a[i];

	ll fact_n = 1;
	// fact_n = 1 * 2 * ... * n
	for(ll i = 1; i <= n; i++){
		fact_n *= i;
		fact_n %= MOD;
	}
	// cout << fact_n << endl;

	ll invs[n+1];
	// invs[i] = 1/i
	for(ll i = 1; i <= n; i++){
		invs[i] = inv(i);
	}

	ll s[n];
	// s[i] = 1/1 + 1/2 + ... + 1/(i+1)
	s[0] = 1;
	for(ll i = 1; i < n; i++){
		s[i] = s[i-1] + invs[i+1];
		s[i] %= MOD;
	}

	ll ans = 0;
	rep(i, n){
		ans += (s[i] + s[n-1-i] - 1) * a[i];
		ans %= MOD;
		// cout << i << " " << ((s[i] + s[n-1-i] - 1) * a[i]) % MOD << endl;
	}
	ans *= fact_n;
	ans %= MOD;

	cout << ans << endl;
}
