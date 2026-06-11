#include <bits/stdc++.h>
#define int long long


using namespace std;
#define N 200005

int dp[1001][1001];


void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int ways(int r, int c) {

    if (dp[0][0] == -1)
        return 0;

    for (int j = 0; j < c; j++) {
        if (dp[0][j] == -1) {
            break;
        }
        dp[0][j] = 1;
    }
    for (int i = 0; i < r; i++) {
        if (dp[i][0] == -1) {
            break;
        }
        dp[i][0] = 1;
    }
    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            if (dp[i][j] == -1)
                continue;

            dp[i][j] = 0;
            if (dp[i][j - 1] != -1)
                dp[i][j] = dp[i][j - 1] % 1000000007;
            if (dp[i - 1][j] != -1)
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % 1000000007;

        }
    }
    if (dp[r - 1][c - 1] == -1)
        return 0;
    // for (int i = 0; i < r; i++) {
    //     for (int j = 0; j < c; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[r - 1][c - 1];


}
int32_t main() {
    c_p_c();
    memset(dp, 0, sizeof dp);
    int r, c;
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char no;
            cin >> no;
            if (no == '#') {
                dp[i][j] = -1;
            }
        }

    }
    cout << ways(r, c);
}
