#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<vector<bool>> dp(N + 1, vector<bool>(1 << 24, false));
    dp[0][1] = true;

    int D;
    for (int i = 1; i <= N; i++)
    {
        cin >> D;
        if (D == 0)
        {
            continue;
        }
        for (int j = 0; j < (1 << 24); j++)
        {
            if (dp[i - 1][j])
            {
                if (j != (j | (1 << D)))
                {
                    dp[i][(j | (1 << D))] = true;
                }
                if (j != (j | (1 << (24 - D))))
                {
                    dp[i][(j | (1 << (24 - D)))] = true;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < (1 << 24); i++)
    {
        if (dp[N][i])
        {
            int s = INT_MAX;
            bitset<24> b(i);
            for (int j = 0; j < 24; j++)
            {
                for (int k = 0; k < j; k++)
                {
                    if (b[j] && b[k])
                    {
                        int d = j - k;
                        s = min(s, min(d, 24 - d));
                    }
                }
            }
            if (s != INT_MAX)
            {
                ans = max(ans, s);
            }
        }
    }
    cout << ans << endl;
}
