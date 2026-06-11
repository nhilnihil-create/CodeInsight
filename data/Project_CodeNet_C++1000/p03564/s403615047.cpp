#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
int64_t MAX = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> dp(N + 1);
    dp[0] = 1;
    for (int i = 1; i < N + 1; i++)
        dp[i] = min(dp[i - 1] * 2, dp[i - 1] + K);
    cout << dp[N];
}