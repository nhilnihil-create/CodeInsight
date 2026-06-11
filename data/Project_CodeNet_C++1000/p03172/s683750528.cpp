#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll max_N = 105, max_K = 1e5 + 50, MOD = 1e9 + 7;
ll N, K, arr[max_N], DP[max_N][max_K];

int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    DP[0][0] = 1;
    ll dp_presum[max_K];
    for (int j = 0; j <= arr[0]; ++j)
        DP[0][j] = 1;
    dp_presum[0] = DP[0][0];
    for (int j = 1; j < max_K; ++j)
        dp_presum[j] = dp_presum[j - 1] + DP[0][j];
    for (int i = 1; i < N; ++i)
    {
        for (int j = 0; j <= K; ++j)
        {
            DP[i][j] = dp_presum[j];
            if (j > arr[i])
                DP[i][j] = (DP[i][j] - dp_presum[j - arr[i] - 1] + MOD) % MOD;
        }
        dp_presum[0] = DP[i][0];
        for (int j = 1; j < max_K; ++j)
            dp_presum[j] = (dp_presum[j - 1] + DP[i][j]) % MOD;
    }
    cout << DP[N - 1][K] << "\n";
}