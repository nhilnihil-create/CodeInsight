#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int MAX = 305;
const int NIL = -1;
const ll LINF = 1LL << 50;
const int mod = 1e+9 + 7;
/* global variables */
/* funciton */
/* main */
int main() {
    int N;
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];


    // sum(a[i], ... , a[j]) = cum[j+1] - cum[i];
    vector<ll> cum(N+2);
    for (int i = 0; i <= N; i++) cum[i+1] = cum[i] + a[i];

    // dp[x][y] = a[x] ~ a[y-1]までを合体させる時の最小コスト
    vector<vector<ll>> dp(N+1, vector<ll>(N+1, LINF));
    for (int i = 0; i < N; i++) { dp[i][i+1] = 0; }
    for (int len = 1; len <= N; len++) {
        for (int x = 0; x <= N - len; x++) {
            int y = x + len;
            for (int z = x + 1; z < y; z++) {
                ll cost = dp[x][z] + dp[z][y] + (cum[z]-cum[x]) + (cum[y] - cum[z]);
                dp[x][y] = min(dp[x][y], cost);
            }
        }
    }

    cout << dp[0][N] << '\n';
}