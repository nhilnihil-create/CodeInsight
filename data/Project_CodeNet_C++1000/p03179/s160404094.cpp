#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[3000][3000] = {};

void add(int &a, int b) {
    a = (a + b) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    string s;
    cin >> n >> s;

    for (int j=0; j<n; j++)
        dp[0][j] = 1;
    for (int i=1; i<n; i++)
        for (int j=0; j<=i; j++) {
            if (s[i-1] == '<')
                add(dp[i][j], j > 0 ? dp[i-1][j-1] : 0);
            else
                add(dp[i][j], (dp[i-1][i-1] - (j > 0 ? dp[i-1][j-1] : 0) + MOD) % MOD);
            if (j > 0)
                add(dp[i][j], dp[i][j-1]);
        }

    cout << dp[n-1][n-1] << "\n";

    return 0;
}
