#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long
int dp[100010][4];

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S; cin >> S;
    dp[0][0] = 1;
    int ans = 0;
    int times = 1;
    rep(i, S.length()) {
        rep(j, 4) {
            dp[i + 1][j] += dp[i][j] * (1 + (S[i] == '?') * 2)% mod;
            dp[i + 1][j] %= mod;
        }
        //if(S[i] == '?') dp[i][0] += (dp[i][0] * 3) % mod;
        if (S[i] == 'A' || S[i] == '?') {
            dp[i + 1][1] += dp[i][0];
            dp[i + 1][1] %= mod;
        }
        if(S[i] == 'B' || S[i] == '?') {
            dp[i + 1][2] += dp[i][1];
            dp[i + 1][2] %= mod;
        }
        if (S[i] == 'C' || S[i] == '?') {
            dp[i + 1][3] += dp[i][2];
            dp[i + 1][3] %= mod;
        }
        
        // rep(j, 4) {
        //     cout << dp[i + 1][j] << " ";
        // }
        // cout << endl;
    }
   
    //cout << ans << endl;
    cout << dp[S.length()][3] << endl;

    return 0;
}

// A ? ? C



//   A B C
// 1 0 0 0
// 1 1 0 0 
// 1 3 1 0
// 1 ? 6 1
//       7

// A

// AA
// AB
// AC

// AAA
// AAB 1
// AAC
// ABA 1
// ABB 2
// ABC 1
// ACA
// ACB 1
// ACC