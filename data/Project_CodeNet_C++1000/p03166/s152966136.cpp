# include <bits/stdc++.h>
# define int long long
# define fi first
# define se second

using namespace std ;

const int N = 1e5 + 1 ;
int v[N], us[N], mx, ans ;
vector < int > vc[N] ;

int dfs( int u ) {
    if( us[u] ) return us[u] ;
    int mx = 0 ;
    for( auto i : vc[u] ) {
        mx = max( mx, dfs( i ) + 1 ) ;
    }
    us[u] = mx ;
    return mx ;
}

int32_t main() {
    //freopen("haybales.in", "r", stdin ) ;
    //freopen("haybales.out", "w", stdout ) ;
    int n, m ;
    cin >> n >> m ;
    for( int i = 1 ; i <= m ; i ++ ) {
        int x, y ;
        cin >> x >> y ;
        vc[x].push_back(y) ;
    }
    for( int i = 1 ; i <= n ; i ++ ) {
        if( !us[i] ) {
            ans = max( ans, dfs( i ) ) ;

        }
    }
    cout << ans << endl;
}
