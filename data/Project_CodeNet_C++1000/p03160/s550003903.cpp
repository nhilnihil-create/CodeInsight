#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0; cin >> n;
    vector<int> costs(n);
    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = abs(costs[1] - costs[0]);
    for (int i = 3; i <= n; i++) {
        int option1 = dp[i - 2] + abs(costs[i - 1] - costs[i - 3]);
        int option2 = dp[i - 1] + abs(costs[i - 1] - costs[i - 2]);
        dp[i] = min(option1, option2);
    }
    cout << dp[n] << '\n';
    return 0;
}