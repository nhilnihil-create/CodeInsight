#include <bits/stdc++.h>

using namespace std;

const int N = 3e3+10;

double dp[N][N];

int main() {
    int n;
    cin >> n;
    vector<double> p(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int cnt = 0; cnt <= n; ++cnt) {
            dp[i][cnt] = dp[i-1][cnt-1] * p[i] + dp[i-1][cnt] * (1.0-p[i]);
        }
    }
    double ans = 0;
    for (int cnt = 0; cnt <= n; ++cnt) {
        if (cnt > n-cnt) {
            ans += dp[n][cnt];
        }
    }
    cout << setprecision(20) << fixed << ans;
    return 0;
}