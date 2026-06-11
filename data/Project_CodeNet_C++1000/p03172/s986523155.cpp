#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define xx first
#define yy second

const int N = 1e2 + 1;
const int K = 1e5 + 1;
const int mod = 1e9 + 7;

int add(int x, int y) {
    return ((x + y) % mod + mod) % mod;
}

int a[N], dp[N][K];

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        fill(dp[i], dp[i] + k + 1, 0);
    for (int i = 0; i <= a[0]; i++)
        dp[0][k - i] = 1;
    for (int i = 0; i < k; i++)
        dp[0][i + 1] = add(dp[0][i + 1], dp[0][i]);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            int x = 0;
            if (j) 
                x = add(x, -dp[i - 1][j - 1]);
            x = add(x, dp[i - 1][min(k, j + a[i])]);
            dp[i][j] = x;
        }
        for (int j = 0; j < k; j++)
            dp[i][j + 1] = add(dp[i][j + 1], dp[i][j]);
    }

    cout << dp[n - 1][0] << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int _; cin >> _; while (_--)
    solve();
    return 0;
}
