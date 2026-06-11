#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> h(n), dp(n, INT_MAX);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        for(int j = i - 1; j >= max(i - k, (long long) 0); j--){
            dp[i] = min (dp[i], dp[j] + abs(h[i] - h[j]));
        }
    }
    cout << dp[n - 1];
    return 0;
}