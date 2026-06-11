#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll ; 
typedef long double ld ;
typedef pair<ll , ll> pll ;

const ll N = 2e5 + 30 , Mod = 1e9 + 7 ;
const ll SQ = 330 ;
ll a[N] , b[N] ;
vector<pair<ll , pll> > v ;
int main () {
    ios::sync_with_stdio(0), cin.tie(0) ;
    ll n ;
    cin >> n ;
    for (int i = 1 ; i <= n ; i ++) {
    	cin >> a[i] >> b[i] ;
    	v.pb({a[i] + b[i] , {a[i] , b[i]}}) ;
	}
	sort(all(v)) ;
	reverse(all(v)) ;
	ll ans = 0 ;
	for (int i =0 ; i < v.size() ; i ++) {
		if (i & 1) {
			ans -= v[i].S.S ;
		}
		else ans += v[i].S.F ;
	}
	cout << ans ;
    
    return (0) ;
}