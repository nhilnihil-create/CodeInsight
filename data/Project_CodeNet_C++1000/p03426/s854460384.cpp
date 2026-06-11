#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__

int main() {
    int H, W, D; cin >> H >> W >> D;
    vector<vector<int>> A(H, vi(W));
    rep(i, H) { rep(j, W) { cin >> A[i][j]; } }
    int Q; cin >> Q;
    vi L(Q), R(Q); rep(i, Q) { cin >> L[i] >> R[i]; }

    map<int, pair<int, int>> G;
    rep(i, H) { rep(j, W) { G[A[i][j]] = make_pair(i, j); } }

    vl suma(H * W + 1);
    for (int i = (H * W - D + 1); i <= H * W; i++) {
        suma[i] = 0;
    }
    for (int i = (H * W - D); i >= 1; i--) {
        suma[i] += suma[i + D];
        ll a = abs(G[i].first - G[i + D].first) + abs(G[i].second - G[i + D].second);
        suma[i] += a;
    }

    // rep(i, H * W + 1) {
    //     cout << "i: " << i << ", suma[i]: " << suma[i] << endl;
    // }

    rep(i, Q) {
        cout << suma[L[i]] - suma[R[i]] << endl;
    }
}