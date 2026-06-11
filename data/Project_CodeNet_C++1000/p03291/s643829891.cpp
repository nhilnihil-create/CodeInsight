#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

const ll MOD = 1000000007;

void f(ll &a, ll b) {
    a = (a + b) % MOD;
}

int main() {
    string S;
    cin >> S;

    vector<vector<ll>> dp(S.size() + 1, vector<ll>(4));
    dp[0][0] = 1;

    for (int i = 0; i < S.size(); i++) {
        if (S.at(i) == '?') {
            f(dp[i + 1][0], 3 * dp[i][0]);
            f(dp[i + 1][1], 3 * dp[i][1]);
            f(dp[i + 1][2], 3 * dp[i][2]);
            f(dp[i + 1][3], 3 * dp[i][3]);
        } else {
            f(dp[i + 1][0], dp[i][0]);
            f(dp[i + 1][1], dp[i][1]);
            f(dp[i + 1][2], dp[i][2]);
            f(dp[i + 1][3], dp[i][3]);
        }

        if (S.at(i) == 'A') {
            f(dp[i + 1][1], dp[i][0]);
        } else if (S.at(i) == 'B') {
            f(dp[i + 1][2], dp[i][1]);
        } else if (S.at(i) == 'C') {
            f(dp[i + 1][3], dp[i][2]);
        } else if (S.at(i) == '?') {
            f(dp[i + 1][1], dp[i][0]);
            f(dp[i + 1][2], dp[i][1]);
            f(dp[i + 1][3], dp[i][2]);
        }
    }

    cout << dp[S.size()][3] << endl;
}