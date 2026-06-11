#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<vector<bool>> dp(N + 1, vector<bool>(1 << 25, false));
    dp[0][0] = true;

    int D;
    vector<int> duplicate(25, 0);
    duplicate[0]++;
    for (int i = 1; i <= N; i++)
    {
        cin >> D;
        duplicate[min(D, 24 - D)]++;
        if (duplicate[min(D, 24 - D)] > 2)
        {
            cout << 0 << endl;
            return 0;
        }

        for (int j = 0; j < (1 << 24); j++)
        {
            if (dp[i - 1][j])
            {
                if ((j >> D) ^ 1)
                {
                    dp[i][(j | (1 << D))] = true;
                }
                if (D != 0 && (j >> (24 - D)) ^ 1)
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
            bitset<24> b(i + 1);
            int count = 0;
            for (int j = 0; j < 24; j++)
            {
                if (b[j])
                {
                    count++;
                }
                for (int k = 0; k < j; k++)
                {
                    if (b[j] && b[k])
                    {
                        s = min(s, min((j - k), 24 - (j - k)));
                    }
                }
            }
            // cout << N + 1 << " " << count << " " << i << endl;
            // assert(count == N + 1);
            if (s != INT_MAX && count == N + 1)
            {
                ans = max(ans, s);
            }
        }
    }
    cout << ans << endl;
}
