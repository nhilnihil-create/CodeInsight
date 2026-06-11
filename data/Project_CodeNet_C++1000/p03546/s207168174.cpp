#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int H, W; cin >> H >> W;
    vector G(10, vector(10, 0));
    rep(i,10) rep(j,10) cin >> G[i][j];
    rep(k,10) rep(i,10) rep(j,10) {
        int n = G[i][k] + G[k][j];
        if (G[i][j] > n) G[i][j] = n;
    }
    vector WA(H, vector(W, -1));
    int res = 0;
    rep(i,H) rep(j, W) {
        cin >> WA[i][j];
        if (WA[i][j] != -1) res += G[WA[i][j]][1];
    }
    cout << res << endl;
}
