// https://atcoder.jp/contests/dp/tasks/dp_c
#include <bits/stdc++.h>
using namespace std;
int n;
typedef vector<int> vi;
typedef vector<vi> vii;
#define rep(i, k, n) for (int i = k; i < (int)(n); i++)
int main()
{
    cin >> n;
    vii hs(n, vi(3));
    rep(i, 0, n)
    {
        cin >> hs[i][0] >> hs[i][1] >> hs[i][2];
    }
    vii dp(n, vi(3));
    dp[0][0] = hs[0][0];
    dp[0][1] = hs[0][1];
    dp[0][2] = hs[0][2];
    rep(i, 1, n)
    {
        rep(j, 0, 3)
        {
            dp[i][j] = max(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + hs[i][j];
        }
    }
    int ans = 0;
    rep(i, 0, 3) ans = max(ans, dp[n - 1][i]);
    cout << ans << endl;
}