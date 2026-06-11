#include "bits/stdc++.h"
using namespace std ;

#define timesaver ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll ;
typedef long double ldb ;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define nl '\n'

#define all( x ) x.begin(),x.end() 
#define sz( x ) ( int )( x ).size( )
#define mem( a, val ) memset(a, val, sizeof( a ) )
#define deci( x ) cout<<fixed<<setprecision( x );
#define bitcount( x ) __builtin_popcountll( x )

const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

const int MAX = 1<<17 ;
const ll INF = 1e18 ;
const int MOD = 1e9 + 7 ;

ll n, mat[17][17], cost[MAX], dp[MAX] ;

void sol( ){
    cin >> n ;
    for( int i = 0 ; i < n ; i++ )
        for( int j = 0 ; j < n ; j++ )
            cin >> mat[i][j] ;
    for( int i = 1 ; i < MAX ; i++ ){
        for( int j = 0 ; j < 17 ; j++ ){
            if( i&(1<<j) )
                for( int k = 0 ; k < 17 ; k++ ){
                    if( i&(1<<k) )
                        cost[i] += mat[j][k] ;
                }
        }
        cost[i] >>= 1 ;
    }
    for( int i = 1 ; i < MAX ; i++ ){
        for( int j = i ; j ; j = (j-1)&i ){
            dp[i] = max( dp[i], dp[i^j] + cost[j] ) ;
        }
    }
    cout << dp[(1LL<<n)-1] << nl ;
}

signed main( ){
  timesaver ;
//  int t = 1 ; cin >> t ; while(t--)
  {
      sol( );
  }
}