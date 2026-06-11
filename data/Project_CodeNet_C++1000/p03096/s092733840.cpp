#include<bits/stdc++.h>
using namespace std ;
#define pb push_back
#define ll long long
ll N = 200007 ;
ll mod = 1000 * 1000 * 1000 + 7 ;
int main() {
    ll n ;
    cin >> n ;
    vector<ll>v(n) ;
    ll i ;
    for ( i = 0 ; i< n ;i++) cin >> v[i] ;
    vector<ll>dp(n+1,0) , last(N+1,0) ;
    dp[0] = 1 ;
    last[v[0]] = 1 ;
    for (i = 1 ; i< n ;i++) {
        if (v[i]==v[i-1] ) {
            dp[i]= dp[i-1] ;
            continue ;
        }
        dp[i] = dp[i-1]+last[v[i]] ;
        dp[i]%=mod ;
        last[v[i]]= dp[i] ;
        //cout << dp[i] << endl ;

    }

    cout << dp[n-1] << endl ;

}
