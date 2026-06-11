#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    rep(i, N) cin >> P[i];

    vector<int> dp(N + 1, 0);
    int k = 0;
    rep(i, N) {
        int p = P[i];
        dp[p] = dp[p - 1] + 1;
        chmax(k, dp[p]);
    }

    int ans = N - k;
    cout << ans << endl;
}
