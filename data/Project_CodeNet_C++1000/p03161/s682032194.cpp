#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

#define INF ((1<<30)-1)
#define LLINF (1LL<<60)
#define EPS (1e-10)

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> h(N);
    rep(i, N) cin >> h[i];

    vector<int> dp(N, INF);
    dp[0] = 0;
    for (int i = 1; i < N; ++i) {
        for (int k = 1; k <= K; ++k) {
            if (i - k >= 0) {
                dp[i] = min(dp[i], dp[i-k] + abs(h[i] - h[i-k]));
            }
        }
    }

    cout << dp[N-1] << endl;
}
