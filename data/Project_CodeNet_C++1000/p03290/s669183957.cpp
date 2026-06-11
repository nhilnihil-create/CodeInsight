#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
using ll = long long;
const int inf = 1e9;
int main() {
    int d;
    ll g;
    scanf("%d %lld", &d, &g);

    vector<ll> p(d), c(d);
    rep(i, d) scanf("%lld%lld", &p[i], &c[i]);

    ll res = inf;

    // 全完するかしないかの2とおりをd乗（問題数分）繰り返す
    for (int bit = 0; bit < (1 << d); ++bit) {
        ll point = 0;
        ll num = 0;
        rep(i, d) {

            // 1が立ってれば（その問題を全完する場合）
            if (bit & (1 << i)) {

                // 合計ポイント加算
                point += c[i] + p[i] * 100 * (i + 1);
                // 問題を解いた数。全完した場合なので++ではなくp[i]
                num += p[i];
            }
        }

        // 全完だけで目標をクリアした場合、一番少ない特典を取得
        if (point >= g) {
            res = min(res, num);
        }

        // 全完だけではクリアできなかった場合
        else {
            for (int i = d - 1; i >= 0; --i) {

                // その問題を全完してる場合次のループ
                if (bit & (1 << i)) continue;

                // 全完してなかったら目標を超えるまで、その問題がある限り、その問題を解く
                for (int j = 0; j < p[i]; ++j) {
                    if (point >= g) break;
                    point += 100 * (i + 1);
                    ++num;
                }
            }

            res = min(res, num);
        }
    }
    
    printf("%lld", res);
    return 0;
}