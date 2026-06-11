
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 16;
int n;
ll a[N][N], sum[1 << N], dp[1 << N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for(int mask = 1; mask < (1 << n); mask++) {
        for(int i = 0; i < n; i++) {
            if((mask >> i) & 1) {
                for(int j = i + 1; j < n; j++) {
                    if((mask >> j) & 1) {
                        sum[mask] += a[i][j];
                    }
                }
            }
        }
    }
    for(int mask = 1; mask < (1 << n); mask++) {
        dp[mask] = LLONG_MIN;
        for(int b = mask; b > 0; b = (b - 1) & mask) {
            dp[mask] = max(dp[mask], sum[b] + dp[mask - b]);
        }
    }
    cout << dp[(1 << n) - 1] << endl;
}