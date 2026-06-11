#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

#define INF ((1<<30)-1)
#define LLINF (1LL<<60)
#define EPS (1e-10)

int v[101010][3];
int dp[101010][3];

int main() {
    int N;
    cin >> N;
    rep(i, N) {
        rep(j, 3) cin >> v[i][j];
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (j == k) continue;
                dp[i][j] = max(dp[i][j], dp[i-1][k] + v[i-1][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 3; ++i) ans = max(ans, dp[N][i]);
    cout << ans << endl;
}
