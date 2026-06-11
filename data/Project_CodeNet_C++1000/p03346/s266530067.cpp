/*
        ঘরে থাকুন , সুস্থ থাকুন ।
    wan-_-s
*/
#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define stay_home_stay_safe return 0
#define pb push_back
//const ll N = 200007 ;
void scan(ll &n) { scanf("%lld",&n) ; }
void scan(ll &n, ll &m) { scanf("%lld%lld",&n,&m) ; }
void scan(vector<ll> &v) { ll n = v.size() ; for(ll i=0 ;i<n;i++) scanf("%lld",&v[i]) ; }
//vector<ll> adj[N] ;


void sol () {
    ll n ,i ;
    cin >> n ;
    vector<ll> v(n) ;
    for ( i = 0 ; i <n ;i++) cin >> v[i] ;
    map<ll,ll> mp ;
    ll ans =1 ;
    for ( i = 1 ; i<= n ; i++) {
        ll x = (i + v[i%n]  )%n ;
        x+=n ;
        x%=n ;
        mp[x]++ ;
        if (mp[x]>1) ans = 0 ;
    }
    cout << (ans == 1 ? "YES\n" : "NO\n" ) ;

}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll n , i ;

    cin >> n ;
    vector<ll>v(n),pos(n) ;
    for ( i= 0 ; i< n;i++) cin >> v[i] ;
    for ( i = 0 ; i< n ;i++) pos[v[i]-1]= i ;
    ll in = 1 , mx = 1  ;
    for ( i = 0 ; i< n-1 ;i++) {
        if ( pos[i]<pos[i+1] ) {
            in++ ;
        }
        else {
            mx = max(mx,in) ;
            in = 1 ;
        }
    }
    cout << n - max(mx,in) << endl ;

    stay_home_stay_safe ;
}




