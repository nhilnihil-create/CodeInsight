#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10e5+5;

int n;
int arr[MAXN][3];
long long dp[MAXN][3];

long long max(long long a, long long b) { return a > b ? a : b; }

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 3; i++) dp[0][i] = arr[0][i];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0) dp[i][j] = max(dp[i-1][j+1]+arr[i][j], dp[i-1][j+2]+arr[i][j]);
            else if (j == 1) dp[i][j] = max(dp[i-1][j-1]+arr[i][j], dp[i-1][j+1]+arr[i][j]);
            else dp[i][j] = max(dp[i-1][j-1]+arr[i][j], dp[i-1][j-2]+arr[i][j]);
        }
    }
    int mx = 0;
    for (int i = 0; i < 3; i++) mx = max(mx, dp[n-1][i]);
    cout << mx << "\n";
    return 0;
}
