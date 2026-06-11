# include <bits/stdc++.h>
# define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
# pragma GCC target("avx2")
# pragma GCC optimize("O3")
# pragma GCC optimize("unroll-loops")
# define int long long

using namespace std;

const int N = 3e3 + 7;
const int mod = 1e9 + 7;

double dp[N][N];

int32_t main() {
    speed;
    int n;
    cin >> n;
    vector < double > a(n + 1), b(n + 1);
    for ( int i = 1; i <= n; i++ ) {
        cin >> a[i];
        b[i] = 1.0 - a[i];
        //cout << a[i] << ' ' << b[i] << '\n';
    }
    dp[0][0] = 1;
    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 0; j <= i; j++ ) {
            dp[i][j] += dp[i - 1][j] * b[i];
            if ( j )
                dp[i][j] += dp[i - 1][j - 1] * a[i];
            //cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
        }
    }
    double ans = 0;
    for ( int i = n / 2 + 1; i <= n; i++ ) {
        //cout << i << ' ' << dp[n][i] << '\n';
        ans += dp[n][i];
    }
    cout << setprecision(10) << ans;
}
