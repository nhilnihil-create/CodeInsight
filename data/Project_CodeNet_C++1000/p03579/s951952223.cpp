#include <bits/stdc++.h>

#define int             long long
#define FOR( i, m, n )  for( int (i) = (m); (i) < (n); (i)++ )
#define REP( i, n )     FOR( i, 0, n )
#define REPR( i, m )    for( int (i) = (m); (i) >= 0; (i)-- )
#define REPONE( i, n )  FOR( i, 1, n + 1 )
#define ALL( a )        (a).begin(), (a).end()
#define MP              make_pair

using namespace std;
using P = pair<int, int>;

template<class T>bool chmax( T& a, const T& b ) { if( a < b ) { a = b; return 1; } return 0; }
template<class T>bool chmin( T& a, const T& b ) { if( a > b ) { a = b; return 1; } return 0; }

const int INF = 1e9;
const int INFLL = 1e18;
const int MOD = 1e9 + 7;

vector<int> G[100001];
vector<int> color;
int N, M, black = 0, white = 0;

bool dfs( int v, int c ){
    color[v] = c;
    if( c ) black++;
    else white++;
    for( auto nv : G[v] ){
        if( color[nv] != -1 ){
            if( color[v] == color[nv] ) return false;
            continue;
        }

        if( !dfs( nv, c ^ 1 ) ) return false;
    }
    return true;
}

signed main(){
    cin >> N >> M;
    REP( i, M ){
        int from, to; cin >> from >> to;
        from--, to--;
        G[from].push_back( to );
        G[to].push_back( from );
    }

    color.assign( N, -1 );

    if( dfs( 0, 0 ) ){
        cout << black * white - M << endl;
    }else{
        cout << N * ( N - 1 ) / 2 - M << endl;
    }
}
