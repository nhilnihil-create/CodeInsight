#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

const int INF = 1e9 + 1;

int main() {
    int N;
    cin >> N;
    vector<double> t(N), v(N);
    rep(i, N) cin >> t[i];
    rep(i, N) cin >> v[i];

    // 全体のT秒を求める
    int T = 0;
    rep(i, N) T += t[i];

    vector<double> maxV(2 * T + 1, (double) INF);

    // maxのスピードをv[i]で初期化
    int nowT = 0;
    rep(i, N) {
        rep(ti, t[i]) {
            int t1 = nowT + ti * 2;
            int t2 = nowT + ti * 2 + 1;
            chmin(maxV[t1], v[i]);
            chmin(maxV[t2], v[i]);
        }
        nowT += t[i] * 2;
        chmin(maxV[nowT], v[i]);
    }

    // 0秒とT秒は0(静止)
    maxV[0] = maxV[T * 2] = 0.0;

    // 前から比較
    rep(ti, 2 * T) maxV[ti + 1] = min(maxV[ti + 1], maxV[ti] + 0.5);

    // 後ろから比較
    for (int ti = 2 * T - 1; ti >= 0; ti--) maxV[ti] = min(maxV[ti], maxV[ti + 1] + 0.5);

    double ans = 0.0;
    // 区間ごとの台形の面積を足す
    rep(i, 2 * T) ans += (maxV[i] + maxV[i + 1]) * 0.5 / 2.0; // (上底 + 下底) * 高さ / 2

    printf("%.4f\n", ans);
}