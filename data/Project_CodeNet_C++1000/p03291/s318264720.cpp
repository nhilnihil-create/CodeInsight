#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;

const int MOD = 1000000007;

long long dp[200000][5];

void add(long long &a, long long b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int main() {
    string S;
    cin >> S;

    dp[0][0] = 1;

    rep(i, S.size()) {
        char c = S[i];

        for (int j = 0; j < 4; ++j) {
            if (S[i] != '?') add(dp[i + 1][j], dp[i][j]);
            else add(dp[i + 1][j], dp[i][j] * 3 % MOD);
        }

        if (S[i] == 'A' || S[i] == '?') add(dp[i + 1][1], dp[i][0]);
        if (S[i] == 'B' || S[i] == '?') add(dp[i + 1][2], dp[i][1]);
        if (S[i] == 'C' || S[i] == '?') add(dp[i + 1][3], dp[i][2]);
    }

    cout << dp[S.size()][3];
}