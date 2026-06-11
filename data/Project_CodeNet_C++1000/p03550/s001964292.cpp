#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;

int main() {
    ll N, Z, W;
    cin >> N >> Z >> W;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    vector<vector<ll>> dp(N + 1, vector<ll>(2));
    for (int i = N - 1; i >= 0; i--) {
        // 先手番
        dp[i][0] = -INF;
        ll Y = (i ? A[i - 1] : W); // 先手番がi番目以降の手札を取れる時、後手番はi-1番目の手札を取っている(i=0の時はW)
        chmax(dp[i][0], abs(Y - A[N - 1])); // すべての手札を取った場合
        for (int j = i + 1; j < N; j++) chmax(dp[i][0], dp[j][1]); //途中までの手札を取った場合

        // 後手番も先手番と同様の更新をする
        dp[i][1] = INF;
        ll X = (i ? A[i - 1] : Z);
        chmin(dp[i][1], abs(X - A[N - 1]));
        for (int j = i + 1; j < N; j++) chmin(dp[i][1], dp[j][0]);
    }

    cout << dp[0][0] << endl;
}