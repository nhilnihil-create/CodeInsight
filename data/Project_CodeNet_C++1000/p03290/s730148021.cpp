#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;

int main() {
    //入力
    int d, g;
    cin >> d >> g;
    vector<int> p(11);
    vector<int> c(11);
    rep(i, d) {
        cin >> p[i] >> c[i];
    }

    //bit全探索
    int ans = INF; //求める答え 最小値を比較していくので初期値はINF
    for (int bit = 0; bit < (1 << d); bit++) {
        int sum = 0; //現在の得点
        int num = 0; //解けた点数
        rep(i, d) {
            if (bit & (1<<i)) { // bit に i 番目のフラグが立っているか
                //i番目のフラグが立っていれば、その難易度の問題を全部解いた事にする
                sum += c[i] + p[i] * 100 * (i+1);
                num += p[i];
            }
        }
        // 自分の得点が g 点以上の場合、問題数が最小値か更新する
        if (sum >= g) {
            ans = min(ans, num);
        // 得点が得点が g 点より小さい場合、得点が高い問題から解く
        } else {
            for (int i = d-1; i >=0; i--) {
                if (bit & (1<<i)) continue; //i番目は上記で解いているので飛ばす
                rep(j, p[i]) {
                    if (sum >= g) break;// 自分の得点が g 点以上の場合z
                    sum += 100 * (i + 1);
                    num++;
                }
            }
            ans = min(ans, num);
        }
    }
    cout << ans << endl;
}
