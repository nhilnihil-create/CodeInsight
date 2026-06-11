#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
const int MOD = 1000000007;

string S;
int dp[100100][4];

signed main() {
    cin >> S;
    dp[0][0] = 1;
    rep(i, S.size()) {
        if (S[i]=='?') dp[i+1][0] = 3*dp[i][0]%MOD;
        else dp[i+1][0] = dp[i][0];
        
        if (S[i]=='A') dp[i+1][1] = (dp[i][1]+dp[i][0])%MOD;
        else if (S[i]=='?') dp[i+1][1] = (3*dp[i][1]+dp[i][0])%MOD;
        else dp[i+1][1] = dp[i][1];
        
        if (S[i]=='B') dp[i+1][2] = (dp[i][2]+dp[i][1])%MOD;
        else if (S[i]=='?') dp[i+1][2] = (3*dp[i][2]+dp[i][1])%MOD;
        else dp[i+1][2] = dp[i][2];
        
        if (S[i]=='C') dp[i+1][3] = (dp[i][3]+dp[i][2])%MOD;
        else if (S[i]=='?') dp[i+1][3] = (3*dp[i][3]+dp[i][2])%MOD;
        else dp[i+1][3] = dp[i][3];
    }
    cout << dp[S.size()][3] << endl;
}