# include <bits/stdc++.h>
# define fi first
# define se second
//# define int long long

using namespace std ;

const int N = 4000 ;
int dp[N][N], ans, se, te;
pair < int, int > pre[N][N], us[N][N];
string s, t ;

int smth( int x, int y ) {
    if( us[x][y].fi ) return us[x][y].se;

    if( x == se || y == te ) return 0 ;

    if( s[x] == t[y] ) {
        pre[x][y] = {x+1, y+1} ;
        us[x][y].se = smth(x+1, y+1 ) +1 ;
        us[x][y].fi = 1 ;
        return smth( x+1, y+1 ) + 1 ;
    }
    int r1 = smth( x+1, y ) ;
    int r2 = smth( x, y+1 ) ;
    if( r1 > r2 ) {
        pre[x][y] = {x+1,y} ;
        us[x][y].se = r1 ;
        us[x][y].fi = 1 ;
        return r1 ;
    }
    pre[x][y] = {x,y+1} ;
    us[x][y].se = r2 ;
    us[x][y].fi = 1 ;
    return r2 ;
}

int32_t main() {
    //freopen("cowsignal.in", "r", stdin ) ;
    //freopen("cowsignal.out", "w", stdout ) ;
	cin >> s >> t ;
	se = s.size() ;
	te = t.size() ;
	int tt = smth( 0, 0 ) ;
	int x = 0, y = 0, xx = 0 ;
	while( true ) {
        if( xx == tt ) break ;
        if( s[x] == t[y] ) {
            cout << s[x] ;
            xx ++ ;
        }
        auto h = pre[x][y] ;
        x = h.fi ;
        y = h.se ;
	}
}
