#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const int INF = 100100;

int main()
{
    int n;
    cin >> n;

    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int pow = 6; pow <= i; pow *= 6)
            if (i - pow >= 0)
                dp[i] = min(min(dp[i - pow] + 1, dp[i - 1] + 1), dp[i]);
        for (int pow = 9; pow <= i; pow *= 9)
            if (i - pow >= 0)
                dp[i] = min(min(dp[i - pow] + 1, dp[i - 1] + 1), dp[i]);
        if (dp[i] == INF)
            dp[i] = dp[i - 1] + 1;
    }

    cout << dp[n] << endl;
    return 0;
}