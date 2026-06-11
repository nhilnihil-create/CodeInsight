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
    vector<vector<int>> a(N, vector<int>(N));
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> a[i][j];

    ll upper = 1 << N;
    // dp[m][s] = Male, m番目まで使った時
    // s : 使ったFemaleをbitで管理
    vector<vector<ll>> dp(N+1, vector<ll>(upper));

    dp[0][0] = 1;
    for (int m = 0; m < N; m++) {
        for (ll s = 0; s < upper; s++) {
            if (__builtin_popcount(s) != (m) || dp[m][s] == 0) continue;
            for (int f = 0; f < N; f++) {
                ll b = 1 << f;
                if (s & b || (a[m][f] == 0)) continue;
                ll nextS = s + b;
                dp[m+1][nextS] += dp[m][s];
                dp[m+1][nextS] %= mod;
            }
        }
    }
    cout << dp[N][upper-1] << '\n';
}