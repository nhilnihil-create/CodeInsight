#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            cin >> a[j][i];
        }
    }
   
    vector<vector<int>>dp(2, vector<int>(n));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            int left = 0, top = 0;
            if(i == 0 && j == 0) {
                left = 0, top = 0;
            }
            else if (j == 0) {
                left = 0;
                top = dp[i - 1][j];
            }
            else if(i == 0) {
                top = 0;
                left = dp[i][j - 1];
            }
            else {
                top = dp[i - 1][j];
                left = dp[i][j - 1];
            }

            dp[i][j] = a[i][j] + max(left, top);
        }
    }
    cout << dp[1][n - 1];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
