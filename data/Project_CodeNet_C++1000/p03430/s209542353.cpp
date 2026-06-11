#include <bits/stdc++.h>
using namespace std;
  
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

const int N = 305;
int dp[N][N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int k;
    cin >> s >> k;

    int n = s.size();

    for (int i = 0; i + 1 < n; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1][0] = 2;
        }
        else {
            dp[i][i + 1][1] = 2;
        }
    }

    for (int i = 0; i < n; i++) {
        dp[i][i][0] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int l = 0, r = i; r < n; l++, r++) {
            for (int h = 0; h <= k; h++) {
                if (l > 0)
                    dp[l - 1][r][h] = max(dp[l - 1][r][h], dp[l][r][h]);
                if (r + 1 < n)
                    dp[l][r + 1][h] = max(dp[l][r + 1][h], dp[l][r][h]);
                if (l > 0 && r + 1 < n) {
                    if (s[l - 1] == s[r + 1]) {
                        dp[l - 1][r + 1][h] = max(dp[l - 1][r + 1][h], dp[l][r][h] + 2);
                    }
                    if (h < k) {
                        dp[l - 1][r + 1][h + 1] = max(dp[l - 1][r + 1][h + 1], dp[l][r][h] + 2);
                    }
                }
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int h = 0; h <= k; h++) {
                ans = max(ans, dp[i][j][h]);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}