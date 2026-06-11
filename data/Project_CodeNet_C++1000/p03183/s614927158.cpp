#include <algorithm>
#include <numeric>
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int w[n], s[n], v[n];
    for (int i = 0; i < n; i++) cin >> w[i] >> s[i] >> v[i];
    int t[n]; iota(t, t+n, 0);
    sort(t, t+n, [&](int i, int j) { return s[i] + w[i] < s[j] + w[j]; });
    long long dp[n][20001] = {};
    dp[0][w[t[0]]] = v[t[0]];
    for (int ii = 1; ii < n; ii++) {
        int i = t[ii];
        for (int j = 0; j <= 20000; j++) dp[ii][j] = dp[ii-1][j];
        for (int j = 0; j <= s[i] && j + w[i] <= 20000; j++)
            dp[ii][j+w[i]] = max(dp[ii][j+w[i]], dp[ii-1][j] + v[i]);
    }
    cout << *max_element(dp[n-1], dp[n]) << endl;
}
