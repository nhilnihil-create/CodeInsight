#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<vector<double>>> dp(n + 1, vector<vector<double>>(n + 1, vector<double>(n + 1)));
    for (int c = 0; c <= n; c++) {
        for (int b = 0; b + c <= n; b++) {
            for (int a = 0; a + b + c <= n; a++) {
                if (a == 0 && b == 0 && c == 0) {
                    continue;
                }
                dp[a][b][c] = n;
                if (a > 0) {
                    dp[a][b][c] += a * dp[a - 1][b][c];
                }
                if (b > 0) {
                    dp[a][b][c] += b * dp[a + 1][b - 1][c];
                }
                if (c > 0) {
                    dp[a][b][c] += c * dp[a][b + 1][c - 1];
                }
                dp[a][b][c] /= a + b + c;
            }
        }
    }
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            a++;
        } else if (x == 2) {
            b++;
        } else {
            c++;
        }
    }
    cout.precision(16);
    cout << fixed << dp[a][b][c] << endl;
}
