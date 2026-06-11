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

ll dp[40][40]  , n;
string s ;
ll calc(ll mask) {
	for (int i =0 ; i < 20 ; i ++) for (int j = 0 ; j < 20  ; j ++) dp[i][j]= 0 ;
	dp[0][0] = 1 ;
	string a = "" , b= "" ;
	for (int i = 0 ; i < n ; i ++) {
		if (mask & (1 << i)) a += s[i] ;
		else b += s[i] ;
	}
	for (int i = 0 ; i <= n  ; i ++) {
		for (int j = 0 ; j <= n ; j ++) {
			if (s[n + n - i - j  - 1] == b[j ]) dp[i][j + 1] += dp[i][j] ;
			if (s[n + n - i - j  - 1] == a[i]) dp[i + 1][j] += dp[i][j] ;
		}
	}
	return  dp[a.size()][b.size()] ;
}
int main () {
    ios::sync_with_stdio(0), cin.tie(0) ;
    
    cin >> n ;
    
    cin >> s ;
	ll ans = 0 ;
    for (int mask = 0 ; mask < (1 << n) ; mask ++) 
    	ans += calc(mask) ;
    cout << ans ;
    
    return (0) ;
}