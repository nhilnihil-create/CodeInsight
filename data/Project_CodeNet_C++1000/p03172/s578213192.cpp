#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int n;
int k;
int dp[110][110000];
vector<int> a;
int main() {
    cin >> n >> k;
    a.resize(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= a[0]; i++) dp[0][i] = 1;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 0; j <= k; j++) {
            sum += dp[i-1][j];
            if (j > a[i]) sum -= dp[i-1][j - a[i] - 1];
            sum %= MOD;
            if (sum < 0) sum += MOD;
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