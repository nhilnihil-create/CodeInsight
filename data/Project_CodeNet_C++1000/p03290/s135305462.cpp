#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll D, G;
vector<ll> p, c;
ll ans = INF;

void dfs(int cnt, vector<ll> v) {
    if (cnt == D) {
        // スコア計算
        // 対象の問題の高い順から計算していく

        // ボーナス取得する問題をセット
        ll score = 0;
        ll question_cnt = 0;
        rep(i, v.size()) {
            if (v[i] == 0) continue;
            score += (i + 1) * 100 * p[i] + c[i];
            question_cnt += p[i];
        }
        // cout << score << " " << question_cnt << endl;

        if (G <= score) {
            ans = min(ans, question_cnt);
            return;
        }

        // 残りは高い問題から埋めていく
        for (int i = D - 1; i >= 0; i--) {
            if (v[i] == 1) continue; 
            // if (p[i] == 1) continue;
            for (int j = p[i] - 1; j >= 0; j--) {
                score += (i + 1) * 100;
                question_cnt++; 

                if (G <= score) {
                    ans = min(ans, question_cnt);
                    return;
                }
            }
        }

        return;
    }

    for (int i = 0; i < 2; i++) {
        v[cnt] = i;
        dfs(cnt + 1, v);
    }
}

int main() {
    cin >> D >> G;
    p.resize(D);
    c.resize(D);
    rep(i, D) cin >> p[i] >> c[i];

    vector<ll> tmp(D, 0);
    dfs(0, tmp);

    cout << ans << endl;
}