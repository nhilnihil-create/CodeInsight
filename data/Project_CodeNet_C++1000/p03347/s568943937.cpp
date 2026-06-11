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



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll n , i ;

    cin >> n ;
    vector<ll>v(n);
    for ( i= 0 ; i< n;i++) cin >> v[i] ;

    ll ans = 0 , res = 1 ;

    for ( i = 0 ; i< n ;i++) {
        if (i==0)  { if (v[i]) res = 0 ; }
        else {
            if (v[i]>v[i-1]+1) res = 0 ;
            else {
                if (v[i]) {
                if ( v[i]-1!=v[i-1] ) ans+= v[i] ;
                else ans++ ;
                }
            }
           //1 cout << ans << endl ;
        }
    }
    if (!res) ans=-1 ;
    cout << ans << endl ;
    stay_home_stay_safe ;
}





