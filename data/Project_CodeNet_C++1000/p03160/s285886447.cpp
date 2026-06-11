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
    int N;
    cin >> N;
    vector<int> h(N);
    rep(i, N) cin >> h[i];

    vector<int> dp(N, INF);
    dp[0] = 0;
    for (int i = 1; i < N; ++i) {
        dp[i] = min(dp[i], dp[i-1] + abs(h[i] - h[i-1]));
        if (i >= 2) {
            dp[i] = min(dp[i], dp[i-2] + abs(h[i] - h[i-2]));
        }
    }

    cout << dp[N-1] << endl;
}
