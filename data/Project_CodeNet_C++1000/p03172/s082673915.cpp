#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> dp(k + 1);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        vector<int> sum(k + 2);
        for (int j = 0; j < k + 1; j++) {
            sum[j + 1] = sum[j] + dp[j];
            sum[j + 1] %= mod;
        }
        for (int j = 0; j < k + 1; j++) {
            dp[j] = (sum[j + 1] - sum[max(0ll, j - a[i])] + mod) % mod;
        }
    }
    cout << dp[k] << endl;
}
