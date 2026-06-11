# include <bits/stdc++.h>
# define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
# pragma GCC target("avx2")
# pragma GCC optimize("O3")
# pragma GCC optimize("unroll-loops")
# define int long long

using namespace std;

const int N = 1e5 + 7;
const int mod = 1e7;

vector < int > adj[N];
int used[N], dp[N];

void dfs( int v ) {
    used[v] = 1;
    for ( auto u: adj[v] ) {
        if ( !used[u] ) {
            dfs( u );
        }
        dp[v] = max( dp[v], dp[u] + 1 );
    }
}

int32_t main() {
    speed;
    int n, m;
    cin >> n >> m;
    for ( int i = 0; i < m; i++ ) {
        int v, u;
        cin >> v >> u;
        adj[v].push_back(u);
    }
    for ( int i = 1; i <= n; i++ ) {
        if ( !used[i] ) {
            dfs( i );
        }
    }
    int mx = 0;
    for ( int i = 1; i <= n; ++i ) {
        mx = max( mx, dp[i] );
    }
    cout << mx;
}
