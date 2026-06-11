#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const ll LINF = 1LL << 50;
const int MAX = 405;
/* global variables */
vector<ll> a(MAX, 0), sum(MAX, 0);
/* function */
ll calcCost(int l, int r) { return sum[r+1] - sum[l]; }
/* main */
int main(){
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) sum[i+1] = sum[i] + a[i];

    vector<vector<ll>> dp(N, vector<ll>(N, LINF));
    for (int i = 0; i < N; i++) dp[i][i] = 0;

    // ex) a0, a1, a2
    // w=1 , a0+a1, a1+a2
    // w=2 , a0+a1+a2 = min{a0+(a1+a2),  (a0+a1)+a2)}
    //   | 0 | 1 | 2
    // 0 | 0 |w=1|w=2
    // 1 |   | 0 |w=1
    // 2 |   |   | 0
    for (int w = 1; w < N; w++) {  // a[i] ~ a[i+w]
        for (int s = 0; s < N-w; s++) {  // start
            int t = s + w;  // end
            // k : 分割候補
            // s | s+1 | ... | t-1 | t
            //   ^     ^     ^     ^
            // のw個
            for (int k = s; k < t; k++) {
                ll cost = calcCost(s, k) + calcCost(k+1, t);
                dp[s][t] = min(dp[s][t], dp[s][k] + dp[k+1][t] + cost);
            }
        }
    }
    cout << dp[0][N-1] << '\n';
}
