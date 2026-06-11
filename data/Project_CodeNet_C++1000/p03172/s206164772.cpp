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
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    vector<vector<ll>> dp(N+1, vector<ll>(K+1));
    vector<ll> cum(K+2);
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        cum[0] = 0;
        for (int j = 0; j <= K; j++) cum[j+1] = cum[j] + dp[i-1][j];
        for (int j = 0; j <= K; j++) {
            ll sum = (cum[j+1] - cum[max(0, j-a[i-1])] + mod) % mod;
            dp[i][j] = max(dp[i][j], sum);
        }
    }
    cout << dp[N][K] << '\n';
}