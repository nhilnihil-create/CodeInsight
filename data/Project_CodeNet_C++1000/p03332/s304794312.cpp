#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll ; 
typedef long double ld ;
typedef pair<ll , ll> pll ;

const ll N = 6e5 + 30 , Mod = 998244353 ;
const ll SQ = 330 ;


ll F[N] , I[N] ;
inline ll sum(ll a , ll b) {
	return (a + b) % Mod ;
}
inline ll mul(ll a , ll b) {
	return (a * b) % Mod ;
}
inline ll pw(ll x , ll y) {
	ll res = 1 ;
	while (y) {
		if (y & 1) res = mul(res , x) ;
		x = mul(x , x) ;
		y >>= 1 ;
	}
	return res ;
}
inline ll C(ll r , ll n) {
	if (r < 0 || r > n) return 0 ;
	return mul(F[n] , mul(I[r] , I[n - r])) ;
}
int main () {
    ios::sync_with_stdio(0), cin.tie(0) ;
    F[0] = 1 ;
    for (int i = 1 ; i < N ; i ++) F[i] = mul(i , F[i - 1]) ;
    I[N - 1] = pw(F[N - 1] , Mod - 2) ;
    for (int i = N - 2 ; i >= 0 ; i --) I[i] = mul(i + 1 , I[i + 1]) ;
    ll n , k ,a , b ;
    cin >> n  >> a >> b >> k ;
	ll ans = 0 ;
	for (int i= 0 ; i < N ; i ++) {
		ll tmp  = i * a ;
		tmp = k - tmp ;
		if (tmp % b) continue ;
		tmp /= b ;
		ans = sum(ans , mul(C(i , n) , C(tmp , n))) ;
	}
	cout << ans ;
    
    return (0) ;
}