#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> x(N), y(N);
    vector<ll> xAry(N), yAry(N); //長方形の四隅の候補

    rep(i, N) {
        cin >> x[i] >> y[i];
        xAry[i] = x[i];
        yAry[i] = y[i];
    }

    sort(xAry.begin(), xAry.end());
    sort(yAry.begin(), yAry.end());

    ll ans = 1e20;
    // 長方形の候補を全部試す
    rep(xi, N) {
        for (int xj = xi + 1; xj < N; xj++) {
            rep(yi, N) {
                for (int yj = yi + 1; yj < N; yj++) {
                    ll lx = xAry[xi], rx = xAry[xj];
                    ll ly = yAry[yi], ry = yAry[yj];

                    //長方形に含まれる座標をカウントする
                    int cnt = 0;
                    rep(i, N) if (lx <= x[i] && x[i] <= rx && ly <= y[i] && y[i] <= ry) cnt++;

                    if (cnt >= K) ans = min(ans, (rx - lx) * (ry - ly));
                }
            }
        }
    }

    cout << ans << endl;
}