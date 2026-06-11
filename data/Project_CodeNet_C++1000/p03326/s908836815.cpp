#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;


int N, M;
vector<ll> X, Y, Z;
vector<vector<ll>> dp;
const ll INF = -1e15;


void input() {
    cin >> N >> M;
    X = Y = Z = vector<ll>(N);
    rep(i, N) cin >> X[i] >> Y[i] >> Z[i];
}


ll solve(int x, int y, int z) {
    dp = vector<vector<ll>>(N + 1, vector<ll>(M + 1, INF));
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        dp[i][0] = 0;
        for (int j = 1; j <= M && j <= i; j++) {
            ll w = X[i-1] * x + Y[i-1] * y + Z[i-1] * z;
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + w);
        }
    }
    return dp[N][M];
}


int main() {
    input();
    ll ans = 0;
    for (int i = -1; i <= 1; i += 2) {
        for (int j = -1; j <= 1; j += 2) {
            for (int k = -1; k <= 1; k += 2) {
                ans = max(ans, solve(i, j, k));
            }
        }    
    }
    cout << ans << endl;
}
