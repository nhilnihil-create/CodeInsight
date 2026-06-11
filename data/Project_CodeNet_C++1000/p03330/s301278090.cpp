#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
#define ALL(v) v.begin(), v.end()
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define chmax(x, a) x = max(x, a)
#define chmin(x, a) x = min(x, a)
#define INF 250000001


int main() {
    int N, C; cin >> N >> C;
    vector<vector<int>> D(C, vector<int>(C));
    rep(i, C) rep(j, C) cin >> D[i][j];
    vector<vector<int>> c(N, vector<int>(N));
    rep(i, N) {
        rep(j, N) {
            cin >> c[i][j];
            c[i][j]--;
        }
    }
    vector<vector<int>> memo(C, vector<int>(3));
    rep(k, C) {
        rep(i, N) {
            rep(j, N) {
                memo[k][(i+j)%3] += D[c[i][j]][k];
            }
        }
    }
    int ans = INF;
    rep(i, C) {
        rep(j, C) {
            rep(k, C) {
                if (i == j || i == k || j == k) continue;
                chmin(ans, memo[i][0]+memo[j][1]+memo[k][2]);
            }
        }
    }
    cout << ans << endl;
}
