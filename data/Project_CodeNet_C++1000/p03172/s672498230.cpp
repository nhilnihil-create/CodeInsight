#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int n;
int k;
long long dp[110][110000];
vector<int> a;
int main() {
    cin >> n >> k;
    a.resize(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        long long sum = 0;
        for (int j = 0; j <= k; j++) {
            sum += dp[i-1][j];
            if (j > a[i]) sum -= dp[i-1][j - a[i] - 1];
            sum = (sum + MOD) % MOD;
            // sum %= MOD;
            // if (sum < 0) sum += MOD;
            // cout << sum << endl;
            dp[i][j] = sum;
        }
        // int cnt = -1;
        // do{
        //     cnt++;
        //     // printf("%d\n", cnt);
        //     for (int j = 0; j <= a[i] && j <= k; j++) {
        //         if (cnt + j < 110000) {
        //             dp[i+1][cnt + j] += dp[i][j];
        //             dp[i+1][cnt + j] %= MOD;
        //         }
        //     }
        // } while (cnt <= k && dp[i][cnt] != 0);
    }
    cout << dp[n][k] << endl;
    return 0;
}