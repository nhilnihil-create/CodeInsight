#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int dp[110000];
    const int inf = 1e9;
    for (auto &v: dp) v = inf;
    dp[0] = 0;
    for (int i = 1; i < 110000; i++) {
        for (int j = 1; i - j >= 0; j *= 6) dp[i] = min(dp[i], dp[i-j] + 1);
        for (int j = 1; i - j >= 0; j *= 9) dp[i] = min(dp[i], dp[i-j] + 1);
    }
    cout << dp[n] << endl;
    return 0;
}