#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout << (x) << endl
#define Int int64_t
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

Int INF = 1e18;
Int mod = 1e9+7;
//Int mod = 998244353;

typedef struct {
    Int y, x;
} p_t;

Int dp[100001][4];

int main() {
    string s;
    cin >> s;
    dp[0][0] = 1;
    for (Int i = 0; i < (Int)s.size(); i++) {
        for (Int j = 0; j < 4; j++) {
            if (s[i] == '?') {
                dp[i + 1][j] += dp[i][j] * 3;
                dp[i + 1][j] %= mod;
            }
            else {
                dp[i + 1][j] += dp[i][j];
                dp[i + 1][j] %= mod;
            }
        }   
        if (s[i] == '?') {
            for (Int j = 0; j < 3; j++) {
                dp[i + 1][j + 1] += dp[i][j];
                dp[i + 1][j + 1] %= mod;
            }
        }
        else {
            dp[i + 1][s[i] - 'A' + 1] += dp[i][s[i] - 'A'];
            dp[i + 1][s[i] - 'A' + 1] %= mod;
        }
    }
    // for (Int i = 0; i < (Int)s.size() + 1; i++) {
    //     for (Int j = 0; j < 4; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    dump(dp[s.size()][3]);
    return 0;
}