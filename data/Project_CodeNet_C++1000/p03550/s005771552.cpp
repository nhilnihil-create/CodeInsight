#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    // dpx[i][j] Xの番で相手がa[i]を持っていて山札の上がa[j]のときの最終スコア
    // dpy[i][j] Yの番で相手がa[i]を持っていて山札の上がa[j]のときの最終スコア
    ll N, Z, W;
    cin >> N >> Z >> W;
    vector<ll> a(N + 2);
    a[0] = Z;
    a[1] = W;
    rep(i, N) cin >> a[i + 2];
    //rep(i, N + 2) cout << a[i] << "\n";
    vector<vector<ll>> dpx(N + 2, vector<ll>(N + 2, 0));
    vector<vector<ll>> dpy(N + 2, vector<ll>(N + 2, 1e18));
    rep(i, N + 1) {
        dpx[i][N + 1] = abs(a[i] - a[N + 1]);
        dpy[i][N + 1] = abs(a[i] - a[N + 1]);
    }
    for (int j = N; j >= 0; j--) {
        rep(i, j) {
            dpx[i][j] = max(dpy[j][j + 1], dpx[i][j + 1]);
            dpy[i][j] = min(dpx[j][j + 1], dpy[i][j + 1]);
        }
    }
    /*
    rep(i, N + 2) {
        rep(j, N + 2) {
            cout << "dpx[" << i << "][" << j << "]=" << dpx[i][j] << "\n";
            cout << "dpy[" << i << "][" << j << "]=" << dpy[i][j] << "\n";
        }
    }
    */
    cout << dpx[1][2] << "\n";
}