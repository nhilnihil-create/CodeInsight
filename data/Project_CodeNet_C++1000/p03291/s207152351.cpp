#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long long dp[2][3] = {};

long long pow3[100000];
void init() {
    pow3[0] = 1;
    for(int i=1; i<100000; ++i) {
        pow3[i] = pow3[i - 1] * 3 % MOD;
    }
}

int main() {
    init();
    string S;
    cin >> S;

    int Q = 0;
    for(int i=0; i<S.size(); ++i) {
        if(S[i] == 'A') {
            dp[(i + 1) & 1][0] = dp[i & 1][0] + pow3[Q];
            dp[(i + 1) & 1][1] = dp[i & 1][1];
            dp[(i + 1) & 1][2] = dp[i & 1][2];
        } else if(S[i] == 'B') {
            dp[(i + 1) & 1][0] = dp[i & 1][0];
            dp[(i + 1) & 1][1] = dp[i & 1][1] + dp[i & 1][0];
            dp[(i + 1) & 1][2] = dp[i & 1][2];
        } else if(S[i] == 'C') {
            dp[(i + 1) & 1][0] = dp[i & 1][0];
            dp[(i + 1) & 1][1] = dp[i & 1][1];
            dp[(i + 1) & 1][2] = dp[i & 1][2] + dp[i & 1][1];
        } else {
            dp[(i + 1) & 1][0] = 3 * dp[i & 1][0] + pow3[Q];
            dp[(i + 1) & 1][1] = 3 * dp[i & 1][1] + dp[i & 1][0];
            dp[(i + 1) & 1][2] = 3 * dp[i & 1][2] + dp[i & 1][1];
            ++Q;
        }
        for(int j=0; j<3; ++j) dp[(i + 1) & 1][j] %= MOD;
    }
    cout << dp[S.size() & 1][2] << endl;
}