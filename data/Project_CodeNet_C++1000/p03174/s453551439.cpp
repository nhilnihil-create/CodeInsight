#include <bits/stdc++.h>

using namespace std;

const int N = 22;
const int mod = 1e9 + 7;
int compatable[N][N];
int dp[N][1 << N];

int main() {
    int n;
    int total = 0;
    cin >> n;

    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            cin >> compatable[i][j];
        }
    }

    dp[0][0] = 1;

    for (int mask = 0; mask < (1 << n) - 1; mask++) {
        int girl = __builtin_popcount(mask);
        for (int men = 0; men < n; men++) {
            if (compatable[men][girl] && !(mask & (1 << men))) {
                dp[girl + 1][mask | (1 << men)] += dp[girl][mask]; 
                dp[girl + 1][mask | (1 << men)] = dp[girl + 1][mask | (1 << men)] % mod;
            }
        }
    }

    cout << dp[n][(1 << n) - 1];
    return 0;
}

