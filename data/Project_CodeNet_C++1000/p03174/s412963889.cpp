#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define xx first
#define yy second

const int N = 21;
const int mod = 1e9 + 7;

int add(int x, int y) {
    return (x + y) % mod;
}
    
int a[N][N], dp[1 << N], ndp[1 << N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    fill(dp, dp + (1 << n), 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < (1 << n); k++)
            ndp[k] = dp[k];

        for (int j = 0; j < n; j++)
            if (a[i][j])
                for (int k = 0; k < (1 << n); k++)
                    if (!(k & (1 << j)))
                        ndp[k | (1 << j)] = add(ndp[k | (1 << j)], dp[k]);

        for (int k =0 ; k < (1 << n); k++)
            dp[k] = ndp[k];
    }
    cout << dp[(1 << n) - 1] << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int _; cin >> _; while (_--)
    solve();
    return 0;
}
