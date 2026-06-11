#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define pci pair <char, int>
#define ppll pair <pll, pll>
#define vll vector <ll>
#define vvll vector <vll>
#define vpll vector <pll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mll map <ll, ll>
#define fastmap gp_hash_table
#define cd complex <double>
#define vcd vector <cd>
#define PI 3.14159265358979
#pragma 03
using namespace std;
using namespace __gnu_pbds;
// yesterday was a series of blunders.
// first failed to properly implement E (which was just really basic dp/brute force), 
// then failed to realize that F is just basic centroid decomposition + dsu.
// (if I could just decently implement that in contest time... 2100 is within reach...)
// such mistakes cannot repeat again.
ll mod = 998244353;
ll fact[300005];
ll binpow(ll a, ll b) {
	if (b == 0) return 1;
	ll x = binpow(a, b/2);
	x *= x; x %= mod;
	if (b % 2) return (x * a) % mod;
	else return x;
}
ll bindiv(ll a, ll b) {
	ll inv = binpow(b, mod - 2);
	return (a * inv) % mod;
}
ll nck(ll n, ll k){
	ll x = (fact[k] * fact[n - k]) % mod;
	return bindiv(fact[n], x);
}
int main(){
	fastio;
	fact[0] = 1; for (ll i = 1; i<300005; i++) fact[i] = (fact[i-1] * i) % mod;
	ll n, a, b, k; cin >> n >> a >> b >> k;
	ll ans = 0;
	for (ll i = 0; i<=n; i++){
		ll j = k - a * i; j /= b;
		if (j <= n && j >= 0 && a * i + b * j == k) (ans += nck(n, i) * nck(n, j)) %= mod;
	}
	cout << ans << endl;
	return 0;
}