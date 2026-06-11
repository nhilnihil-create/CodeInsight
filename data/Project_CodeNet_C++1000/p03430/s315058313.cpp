#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>
#include <tuple>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e5 * 2 + 10, INF = 1e9 + 10, MOD = 1e9 + 7;

const ll SQR = 10000;

ll dp[303][303][303];
bool used[303][303];
string s;
ll k, ans = 0;

void lcs(ll l, ll r) {
    if (used[l][r]) return;
    used[l][r] = 1;
    if (l == r) {
        for (int t = 0; t <= k; t++) {
            dp[l][r][t] = 1;
            ans = max(ans, dp[l][r][t]);
        }
        return;
    } else if (l == r - 1) {
        lcs(l + 1, r);
        lcs(l, r - 1);
        for (int t = 0; t <= k; t++) {
            dp[l][r][t] = 1;
            dp[l][r][t] = max(ll((s[l] == s[r]) * 2), dp[l][r][t]);
            if (t > 0) {
                dp[l][r][t] = max(dp[l][r][t], 2ll);
            }
            ans = max(ans, dp[l][r][t]);
        }
        return;
    } else {
        lcs(l + 1, r);
        lcs(l, r - 1);
        for (int t = 0; t <= k; t++) {
            dp[l][r][t] = max(dp[l + 1][r][t], dp[l][r - 1][t]);
            if (s[l] == s[r]) dp[l][r][t] = max(dp[l + 1][r - 1][t] + 2, dp[l][r][t]);
            if (t > 0) {
                dp[l][r][t] = max(dp[l][r][t], dp[l][r][t - 1]);
                dp[l][r][t] = max(dp[l + 1][r - 1][t - 1] + 2, dp[l][r][t]);
            }
            ans = max(ans, dp[l][r][t]);
        }
    }
}

int main()
{
    fastInp;

    cin >> s;
    cin >> k;

    lcs(0, s.size() - 1);
    cout << ans << "\n";
    return 0;
}