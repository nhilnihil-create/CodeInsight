#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define all(c)  c.begin(), c.end()
#define mp make_pair
#define endl "\n"
#define N 100001
#define INF 1e9


int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    
    ll n , i  ;
    cin >> n ;
    pair<ll , ll >  d[n] ;
    ll siz[n+1] ;
    for(i=0 ; i<n ; i++){
        cin >> d[ i ].F  ;
        d[i].S = i+1 ;
        siz[i+1]=1 ;
    }
    sort(d , d+n) ;
    ll dis=0 ;
    vector<pair<ll , ll > > ans ;
    for(i=n-1 ; i>0 ; i--){
        ll sum = d[i].F-n+2*siz[d[i].S] ;
        ll pos = (ll)(lower_bound(d , d+n , mp(sum , 0LL)) - d) ;
        if(d[pos].F!=sum){cout << -1 ; return 0 ;}
        ll u = d[i].S , v = d[pos].S ;
        ans.pb(mp(u , v)) ;
        siz[v]+=siz[u] ;
        dis+=siz[u] ;
    }
    if(dis!=d[0].F){cout << -1 ; return 0 ;}
    for(i=0 ; i<n-1 ; i++){
        cout << ans[i].F << " " << ans[i].S << endl ;
    }


    return 0 ;
    
}
