#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__

int main() {
    int H, W, D;
    cin >> H >> W >> D;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) {
        rep(j, W) {
            cin >> A[i][j];
        }
    }
    int Q;
    cin >> Q;
    vi L(Q), R(Q);
    rep(i, Q) {
        cin >> L[i] >> R[i];
    }

    vector<pair<int, int>> G(H * W + 1);
    rep(i, H) {
        rep(j, W) {
            G[A[i][j]] = make_pair(i + 1, j + 1);
        }
    }

    // rep(i, H * W + 1) {
    //     cout << "i: " << i << ", G[i]: (" << G[i].first << ", " << G[i].second << ")" << endl;
    // }

    vl sum(H * W + 1);
    for (int i = H * W; i > H * W - D; i--) {
        sum[i] = 0;
    }
    for (int i = H * W - D; i >= 1; i--) {
        sum[i] = sum[i + D] + abs(G[i].first - G[i + D].first) + abs(G[i].second - G[i + D].second);
    }

    // rep(i, H * W + 1) {
    //     cout << "i: " << i << ", sum[i]: " << sum[i] << endl;
    // }

    rep(i, Q) {
        cout << (sum[L[i]] - sum[R[i]]) << endl;
    }
}