#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

const int MAX = 3e3+5;
const int mod = 1e9+7;
int dp[MAX][MAX];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;

    string s;
    cin>>s;
    s = " " + s;

    dp[1][1] = 1;

    for( int i = 2 ; i <= n ; i++ ) {
        for( int j = 1 ; j <= i ; j++ ) {
            if( s[i-1] == '<') {
                dp[i][j] += dp[i-1][j-1];
                dp[i][j] %= mod;
            } else {
                dp[i][j] += ( dp[i-1][i-1] - dp[i-1][j-1] + mod ) % mod;
                dp[i][j] %= mod;
            }

        }
        for( int j = 1 ; j <= i ; j++ )
            dp[i][j] = ( dp[i][j] + dp[i][j-1] ) % mod;

    }


    cout<<dp[n][n]<<"\n";


}
