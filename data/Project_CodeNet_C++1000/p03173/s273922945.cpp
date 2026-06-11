#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (int)((x).size())
#define xx first
#define yy second

const int N = 401;
const ll oo = 1e13;

int a[N];
ll dp[N][N], cost[N][N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int s = 1; s <= n; s++)
        for (int l = 0, r = s - 1; r < n; l++, r++) {
            if (l == r) {
                dp[l][r] = a[l];
                cost[l][r] = 0;
                continue;
            }
            dp[l][r] = oo;
            cost[l][r] = oo;
            for (int j = l; j < r; j++)
                dp[l][r] = min(dp[l][r], dp[l][j] + dp[j + 1][r]); 
            for (int j = l; j < r; j++)
                if (dp[l][r] == dp[l][j] + dp[j + 1][r])
                    cost[l][r] = min(cost[l][r], cost[l][j] + cost[j + 1][r]);
            cost[l][r] += dp[l][r];
        }
    cout << cost[0][n - 1] << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int _; cin >> _; while (_--)
    solve();
    return 0;
}
