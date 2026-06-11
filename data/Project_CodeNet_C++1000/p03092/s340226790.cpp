#include <iostream>
using namespace std;
int main() {
    int n, A, B; cin >> n >> A >> B;
    int p[n]; for (int i = 0; i < n; i++) cin >> p[i];
    long long dp[2][n+1];
    int cur = 0, prev = 1;
    fill(dp[prev], dp[prev]+n+1, 0);
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j <= n; j++) {
            if (j < p[i]) dp[cur][j] = min(dp[prev][p[i]], dp[prev][j] + A);
            else if (j > p[i]) dp[cur][j] = dp[prev][j] + B;
        }
        swap(cur, prev);
    }
    cout << dp[prev][0] << endl;
}
