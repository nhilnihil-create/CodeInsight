#include "bits/stdc++.h"

using namespace std;

using ll = long long;
constexpr int INF = numeric_limits<int>::max() / 2;

int N;
vector<ll> A(1 << 20), sum(1 << 20);
vector<vector<ll>> dp(1 << 20, vector<ll>(2, 0));

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < (1 << N); i++)
    {
        cin >> A[i];
        dp[i][0] = A[i];
        dp[i][1] = -INF;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < (1 << N); j++)
        {
            if (j & (1 << i))
            {
                if (dp[j][0] < dp[j ^ (1 << i)][0])
                {
                    dp[j][1] = max(dp[j][0], dp[j ^ (1 << i)][1]);
                    dp[j][0] = dp[j ^ (1 << i)][0];
                }
                else
                {
                    dp[j][1] = max(dp[j][1], dp[j ^ (1 << i)][0]);
                }
            }
        }
    }
    sum[0] = dp[0][0] + dp[0][1];
    for (int i = 1; i < (1 << N); i++)
    {
        sum[i] = max(sum[i - 1], dp[i][0] + dp[i][1]);
        cout << sum[i] << endl;
    }
}
