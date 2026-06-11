#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 310;

int dp[N][N][N];
string s;

int f(int i, int j, int k) {
    if (dp[i][j][k] != -1) {
        return dp[i][j][k];
    }
    if (i > j) {
        return dp[i][j][k] = 0;
    }
    if (i == j) {
        return dp[i][j][k] = 1;
    }
    if (s[i] == s[j]) {
        return dp[i][j][k] = f(i + 1, j - 1, k) + 2;
    }
    dp[i][j][k] = 0;
    if (k) {
        dp[i][j][k] = f(i + 1, j - 1, k - 1) + 2;
    }
    dp[i][j][k] = max(dp[i][j][k], f(i + 1, j, k));
    dp[i][j][k] = max(dp[i][j][k], f(i, j - 1, k));
    return dp[i][j][k];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> s >> k;
    int n = s.length();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                dp[i][j][k] = -1;
            }
        }
    }
    cout << f(0, n - 1, k);
    return 0;
}