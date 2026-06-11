# include <bits/stdc++.h>
# define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
# pragma GCC target("avx2")
# pragma GCC optimize("O3")
# pragma GCC optimize("unroll-loops")
# define int long long

using namespace std;

const int N = 3e3 + 7;
const int mod = 1e7;

int dp[N][N];
string s, t;

void rec( int n, int m ) {
    if ( n == 0 || m == 0 ) {
        return;
    }
    if ( dp[n][m] != -1 ) {
        return;
    }
    if ( s[n - 1] == t[m - 1] ) {
        rec( n - 1, m - 1 );
        dp[n][m] = max( dp[n][m], dp[n - 1][m - 1] + 1 );
    }
    rec( n - 1, m );
    rec( n, m - 1 );
    rec( n - 1, m - 1 );
    dp[n][m] = max( { dp[n][m], dp[n - 1][m], dp[n][m - 1], dp[n - 1][m - 1] } );
}

int32_t main() {
    speed;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    for ( int i = 0; i <= n; i++ ) {
        for ( int j = 0; j <= m; j++ ) {
            dp[i][j] = -1;
        }
    }
    for ( int i = 0; i <= m; i++ ) {
        dp[0][i] = 0;
    }
    for ( int j = 0; j <= n; j++ ) {
        dp[j][0] = 0;
    }
    rec( n, m );
    string ans;
    while ( n > 0 && m > 0 ) {
        if ( s[n - 1] == t[m - 1] ) {
            ans += s[n - 1];
            n--;
            m--;
        }
        else {
            if ( dp[n - 1][m] >= dp[n][m - 1] ) {
                n--;
            }
            else {
                m--;
            }
        }
    }
    reverse( ans.begin(), ans.end() );
    cout << ans;
}
