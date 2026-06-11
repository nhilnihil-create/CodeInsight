//g++  5.4.0

#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long
#define pb push_back
#define pii pair< int,int >
#define fast ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;

const int mod = 1e9+7;

signed main()
{
    fast;
    int n;
    cin >> n;
    int dp[n+1][n+1];
    memset( dp,0,sizeof(dp));
    dp[1][1] = 1;
    
    for(int len=2 ; len<=n ; len++ )
    {
        int pre[ len ] ;
        pre[0] = 0;
        for(int i=1 ; i<len ; i++ )
            pre[i] = (pre[i-1] + dp[len-1][i])%mod;
        char c;
        cin >> c;
        for(int last=1 ; last<=len ; last++)
        {
            if( c == '<' )
                dp[len][last] = pre[last-1];
            else
                dp[len][last] = (pre[len-1] - pre[last-1] + mod ) %mod;
        }
    }
    /*cout << "\n";
    for(int i=1 ; i<=n ; i++ )
    {
        for(int j=1 ; j<=n ; j++ )
            cout << dp[i][j] << " ";
        cout << "\n";
    }*/
    int ans = 0;
    for(int last=1 ; last <=n ; last++ )
        ans = (ans + dp[n][last] )%mod;
    cout << ans;
}



