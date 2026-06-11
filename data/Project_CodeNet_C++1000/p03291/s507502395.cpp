#include <bits/stdc++.h>
using namespace std;

#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;

const long long INF = 1LL << 60;
const long long MOD = 1000000007;

int main()
{
    string S;
    cin >> S;

    int len = (int)S.size();
    vector<vector<ll>> dp(len + 1, vector<ll>(4, 0));
    dp[0][0] = 1;

    rep(i, len) {
        rep(j, 4) {
            if (S[i] == '?') {
                dp[i + 1][j] += (dp[i][j] * 3) % MOD;
            }
            else {
                dp[i + 1][j] += dp[i][j];
            }
            dp[i + 1][j] %= MOD;
        }
        if (S[i] == 'A' || S[i] == '?') dp[i + 1][1] += dp[i][0];
        if (S[i] == 'B' || S[i] == '?') dp[i + 1][2] += dp[i][1];
        if (S[i] == 'C' || S[i] == '?') dp[i + 1][3] += dp[i][2];
        rep(j, 4) {
            dp[i + 1][j] %= MOD;
        }
    }

    cout << dp[len][3] << endl;
    return 0;
}