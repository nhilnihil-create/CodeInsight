#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

int main()
{
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    vector<vector<int>> dp(n + 1, vector<int>(k + 1)); //dp[i][j] := i人目までみた時に飴をj個使う場合の数
    dp[0][0] = 1;

    for(int i = 0; i < n; i++) {
        vector<ll> sum(k + 1); //sum[i] := i個目までの累積和
        sum[0] = dp[i][0];
        for(int j = 1; j <= k; j++) {
            sum[j] = sum[j - 1] + dp[i][j];
            sum[j] %= mod;
        }

        for(int j = 0; j <= k; j++) {
            dp[i + 1][j] += sum[j] - (j - a[i] - 1 < 0 ? 0 : sum[j - a[i] - 1]);
            dp[i + 1][j] %= mod;
        }

    }
    cout << ((dp[n][k] % mod) + mod) % mod << endl;
}