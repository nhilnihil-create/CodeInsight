#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;

int main() {
    ll N;
    cin >> N;
    string s = to_string(N);
    int keta = s.size();
    int ans = 9 * (keta - 1);

    int dp[keta + 1][2][10]; // smaller
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;

    for (int i = 0; i < keta + 1; i++) {
        for (int j = 0; j < 10; j++) {
            if (dp[i][1][j] != -1)
                dp[i + 1][1][9] = max(dp[i + 1][1][9], dp[i][1][j] + 9);
            if (s[i] - '0' != 0) {
                int num = s[i] - '0' - 1;
                dp[i + 1][1][num] = max(dp[i + 1][1][num], dp[i][0][j] + num);
            }
            int num = s[i] - '0';
            dp[i + 1][0][num] = max(dp[i + 1][0][num], dp[i][0][j] + num);
        }
    }

    rep(j, 10) {
        ans = max(ans, dp[keta][0][j]);
        ans = max(ans, dp[keta][1][j]);
    }

    cout << ans << endl;
}