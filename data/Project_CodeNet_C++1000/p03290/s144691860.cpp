#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
    int D, G;
    cin >> D >> G;
    vector<int> p(D), c(D);
    rep(i, D) cin >> p[i] >> c[i];

    int ans = 100000;
    for (int bit = 0; bit < (1 << D); bit++) {
        int score = 0, cnt = 0;
        // 基本スコア＋コンプリートボーナス
        rep(i, D) {
            if (bit & (1 << i)) {
                score += 100 * (i + 1) * p[i] + c[i];
                cnt += p[i];
            }
        }
        if (score >= G) {
            ans = min(ans, cnt);
            continue;
        }

        // 残りの基本スコアを高い方から順に取得
        for (int i = D - 1; 0 <= i; i--) {
            if (bit & (1 << i)) continue;
            int base = 100 * (i + 1);
            if (score + base * p[i] + c[i] >= G) {
                rep(_, p[i]) {
                    score += base;
                    cnt++;
                    if (score >= G) break;
                }
                break;
            } else {
                score += base * p[i] + c[i];
                cnt += p[i];
            }
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}