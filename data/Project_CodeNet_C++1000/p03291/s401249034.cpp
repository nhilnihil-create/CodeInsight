#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1e5 + 5;
const int INF = 1001001001;
const int MOD = 1e9 + 7;

int main(){
    string S;
    cin >> S;

    int N = S.size();

    vector<vector<ll>> dp(N + 1, vector<ll>(4));
    dp[0][0] = 1;
    rep(i, N) {
        if (S[i] == 'A') {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = dp[i][0] + dp[i][1];
            dp[i + 1][1] %= MOD;
            dp[i + 1][2] = dp[i][2];
            dp[i + 1][3] = dp[i][3];
        } else if (S[i] == 'B') {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = dp[i][1];
            dp[i + 1][2] = dp[i][1] + dp[i][2];
            dp[i + 1][2] %= MOD;
            dp[i + 1][3] = dp[i][3];
        } else if (S[i] == 'C') {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = dp[i][1];
            dp[i + 1][2] = dp[i][2];
            dp[i + 1][3] = dp[i][2] + dp[i][3];
            dp[i + 1][3] %= MOD;
        } else {
            dp[i + 1][0] = dp[i][0] * 3;
            dp[i + 1][0] %= MOD;
            dp[i + 1][1] = dp[i][0] + dp[i][1] * 3;
            dp[i + 1][1] %= MOD;
            dp[i + 1][2] = dp[i][1] + dp[i][2] * 3;
            dp[i + 1][2] %= MOD;
            dp[i + 1][3] = dp[i][2] + dp[i][3] * 3;
            dp[i + 1][3] %= MOD;
        }
    }

    cout << dp[N][3] << endl;
}