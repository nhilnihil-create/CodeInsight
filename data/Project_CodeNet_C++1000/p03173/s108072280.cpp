#include <bits/stdc++.h>
using namespace std;
int n;
using ll = long long;
vector<int> a;
ll sum_cost[440][440];   /// dp[l][r] ==> [l, r)のときの最小値
ll dp[440][440];

ll rec(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (l + 1 == r) return dp[l][r] = 0;
    ll sum_lr = 0;
    for (int i = l; i < r; i++) sum_lr += a[i];
    ll res = 1ll<<60;
    for (int mid = l + 1; mid < r; mid++) {
        res = min(res, rec(l, mid) + rec(mid, r));
    }
    res += sum_lr;
    return dp[l][r] = res;
}
int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < 440; i++) 
        for (int j = 0; j < 440; j++) dp[i][j] = -1;
    // for (int width = 1; width <= n; width++) {
    //     for (int l = 0; l + width <= n; l++) {
    //         int r = l + width;
    //         sum_cost[l][r] = sum_cost[l][r-1] + a[r-1];
    //     }
    // }
    cout << rec(0, n) << endl;
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    return 0;
}