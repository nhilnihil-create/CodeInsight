#include<bits/stdc++.h>
using namespace std ;
#define ll long long
vector<ll> adj[200007] ;
ll vis[200007] ;

void dfs(ll n ) {
    vis[n]=1 ;
    for (auto it : adj[n]) {
        if (!vis[it]) dfs(it) ;
    }

}

int main() {

    ll n , m ;
    cin >> n>> m ;
    while(m--) {
        ll a , b ,c ;
        cin >> a >> b >> c ;
        adj[a].push_back(b) ;
        adj[b].push_back(a) ;
    }
    ll ans = 0 ;
    for (ll i =1 ; i<=n ;i++) {
        if (!vis[i]) {
            dfs(i) ;
            ans++ ;
        }
    }

    cout << ans << endl ;

    return 0 ;
}
