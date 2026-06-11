#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll MOD = 998244353;
const ll dx[4] = { -1,1,0,0 };
const ll dy[4] = { 0,0,-1,1 };
const ll MAX = 7e5 ;
const ll oo = 1e16;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
long long gcd(long long  a, long long  b) { return (b == 0 ? a : gcd(b, a % b)); }
ll n , m  , k , Q , a , b , l , x , y, ans , p , T , G; string s;
ll fact[MAX] , inv[MAX];
ll binpow(ll a, ll b){
	if(b == 0){
		return 1;
	}if(b % 2 == 1) return (binpow(a, b - 1) * a) % MOD;
	else{
		ll x = binpow(a, b / 2);
		return (x * x) % MOD;
	}
}

ll C(ll n, ll k){
	ll x = (inv[k] * inv[n - k]) % MOD;
	return (fact[n] * x) % MOD;
}

ll solve(ll cntA, ll cntB){
    if (cntB > n) return 0;
	return C(n, cntA) * C(n, cntB) % MOD;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    fact[0] = inv[0] = 1;
	for(ll i = 1; i < MAX; i++){
		fact[i] = (fact[i - 1] * i) % MOD;
		inv[i] = (inv[i - 1] * binpow(i , MOD - 2))%MOD;
	}


	cin >> n >> a >> b >> k;
	for(int i = 0; i <= n; i++){
		if(k >= a * i && (k - (i * a)) % b == 0){
			ans += solve(i, (k - (i * a)) / b);
			ans %= MOD;
		}
	}
	cout << ans;




    return 0;
}
