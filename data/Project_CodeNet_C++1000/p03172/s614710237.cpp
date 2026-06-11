// Candies - Educational DP Contest [Cloned] - M
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using iii = pair<ii, int>;
#define vt vector
#define pq priority_queue
#define pb push_back
#define mp make_pair
#define fi first
#define se second
// #define multicase
const int MOD = 1e9 + 7;
const int INF = 2e9;
const int N = 1e2 + 5;
const int K = 1e5 + 5;

int n, k;
int a[N];
int dp[N][K];

int add(int x, int y) {
    int ret = x + y;
    return ret >= MOD ? ret % MOD : ret;
}

int sub(int x, int y) {
    int ret = x - y;
    return ret < 0 ? ret + MOD : ret;
}

void computeDP() {
    dp[0][0] = 1;
    for(int idx = 1; idx <= n; idx++) {
        for(int candy = 0; candy <= k; candy++) {
            int &sol = dp[idx][candy];
            sol = add(dp[idx][candy - 1], dp[idx - 1][candy]);
            sol = sub(sol, (candy - a[idx] - 1 >= 0 ? dp[idx - 1][candy - a[idx] - 1] : 0));
        }
    }
}

void solve() {
    int T = 1;
  #ifdef multicase
    cin >> T;
  #endif
    for(int tc = 1; tc <= T; tc++) {
        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        computeDP();
        cout << dp[n][k] << "\n";
    }
}

int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    
}
// for(int i = 0; i <= a[idx]; i++) {
//     if(candy - i >= 0)
//         sol = add(sol, dp[idx - 1][candy - i]);
// }