#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n)    for (ll (i) = 0;   (i) < (n); ++(i))
#define FOR(i, a, b) for (ll (i) = (a); (i) < (b); ++(i))

const int MOD = (int)1e9 + 7;

int N;
string S;

ll dp[3030][3030];
ll frm[3030];

signed main() {

    cin >> N >> S;

    REP(i, N) dp[1][i] = 1;
    FOR(i, 1, N) {  // dp[i] -> dp[i + 1]
        bool isless = S[i - 1] == '<';
        int mx_i = N - i;
        frm[0] = 0;
        REP(j, mx_i + 1) (frm[j + 1] = frm[j] + dp[i][j]) %= MOD;;
        REP(j, mx_i) {
            if (isless) dp[i + 1][j] = (frm[j + 1] - frm[0] % MOD + MOD) % MOD;
            else        dp[i + 1][j] = (frm[mx_i + 1] - frm[j + 1] % MOD + MOD) % MOD;
            dp[i + 1][j] %= MOD;
        }
    }
    cout << dp[N][0] << endl;

    // REP(i, N + 1) {
    //     REP(j, N + 1) cout << dp[i][j] << ' ';
    //     cout << endl;
    // }

}