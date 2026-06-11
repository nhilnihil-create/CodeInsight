#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N, K; cin >> N >> K;
    vector X(N, 0);
    vector Y(N, 0);
    vector XS(N, 0);
    vector YS(N, 0);
    rep(i, N) {
        int x, y; cin >> x >> y;
        X[i] = x;
        Y[i] = y;
        XS[i] = x;
        YS[i] = y;
    }
    sort(XS.begin(), XS.end());
    sort(YS.begin(), YS.end());

    ll res = INT64_MAX;
    rep(x1, N) {
        for (int x2 = x1 + 1; x2 < N; x2++) {
            rep(y1, N) {
                for (int y2 = y1 + 1; y2 < N; y2++) {
                    int L = XS[x1], R = XS[x2];
                    int B = YS[y1], T = YS[y2];
                    int num = 0;
                    rep(i,N) {
                        int x = X[i], y = Y[i];
                        if (L <= x && x <= R && B<=y && y<=T) num++;
                    }
                    if (num >= K) res = min(res, (ll)(R-L)*(T-B));
                }
            }
        }
    }
    cout << res << endl;
}
