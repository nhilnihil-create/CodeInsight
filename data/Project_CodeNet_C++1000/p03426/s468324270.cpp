#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<ll>> vv;
typedef pair<int, int> P;

const int MAX = 301;

// input
int H, W, D;
int A[MAX][MAX];
int Q;
vector<int> L, R;

map<int, P> m;
int n;
vv w;


void input() {
    cin >> H >> W >> D;
    rep(i, H) rep(j, W) cin >> A[i][j];
    cin >> Q;
    L = R = vector<int>(Q);
    rep(i, Q) cin >> L[i] >> R[i];
}


int dis(P p1, P p2) {
    int ret = max(p1.first - p2.first, p2.first - p1.first);
    ret += max(p1.second - p2.second, p2.second - p1.second);
    return ret;
}


int main() {
    input();
    rep(i, H) rep(j, W) m[A[i][j]] = P(i, j);
    int n = (H * W - 1) / D + 1;
    w = vv(D, vector<ll>(n));
    rep(i, D) {
        w[i][0] = 0;
        int j = 1;
        int x = i + 1 + D;
        while (x <= H * W) {
            P p1 = m[x - D];
            P p2 = m[x];
            w[i][j] = w[i][j - 1] + dis(p1, p2);
            x += D;
            j++;
        }
    }
    rep(i, Q) {
        int l = L[i], r = R[i];
        int v = (l - 1) % D;
        l = (l - 1) / D;
        r = (r - 1) / D;
        int ans = w[v][r] - w[v][l];
        cout << ans << endl;
    }
}
