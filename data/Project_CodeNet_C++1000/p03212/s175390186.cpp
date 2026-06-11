#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;
ll const MAX_N = 100000;
ll const MOD = 1000000007;

int main() {
    string N;
    cin >> N;

    ll n = N.length();
    ll dp[n + 5][2][5];
    rep(i, n + 5) rep(j, 2) rep(k, 5) dp[i][j][k] = 0;

    vector<ll> cnt(3, 0);
    int n0 = N[0] - '0';
    if (n0 == 3 || n0 == 5 || n0 == 7) {
        dp[0][0][1] = 1;
        cnt[(n0 - 1) / 2 - 1]++;
    }

    rep(i, n0) {
        if (i == 3 || i == 5 || i == 7) {
            dp[0][1][1]++;
        }
    }

    rep(i, n - 1) {
        dp[i + 1][1][1] += dp[i][1][1] + 3;
        dp[i + 1][1][2] += 2 * dp[i][1][1];
        dp[i + 1][1][2] += 2 * dp[i][1][2];
        dp[i + 1][1][3] += dp[i][1][2];
        dp[i + 1][1][3] += 3 * dp[i][1][3];

        int ni = N[i + 1] - '0';
        if (ni == 3 || ni == 5 || ni == 7) {
            cnt[(ni - 1) / 2 - 1]++;
            ll idx = 0;
            rep(j, 3) {
                if (cnt[j] != 0) idx++;
            }
            if (idx != 0) dp[i + 1][0][idx] = 1;
        }

        rep(j, ni) {
            if (j == 3 || j == 5 || j == 7) {
                if (cnt[(j - 1) / 2 - 1] == 0) {
                    dp[i + 1][1][2] += dp[i][0][1];
                    dp[i + 1][1][3] += dp[i][0][2];
                } else {
                    dp[i + 1][1][1] += dp[i][0][1];
                    dp[i + 1][1][2] += dp[i][0][2];
                    dp[i + 1][1][3] += dp[i][0][3];
                }
            }
        }
    }

    // rep(i, n) {
    //     rep(j, 2) {
    //         reps(k, 1, 4) { cout << dp[i][j][k] << " "; }
    //     }
    //     cout << endl;
    // }

    cout << dp[n - 1][0][3] + dp[n - 1][1][3] << endl;

    return 0;
}
