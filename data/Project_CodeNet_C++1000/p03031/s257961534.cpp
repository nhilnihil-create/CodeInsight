#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long mod = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(m);
    vector<int> p(m);
    rep(i, m) {
        int k;
        cin >> k;
        s[i].resize(k);
        rep(j, k) cin >> s[i][j];
    }

    rep(i, m) cin >> p[i];

    int ans = 0;
    for(int bit = 0; bit < (1 << n); ++bit) { //スイッチの組み合わせを生成
        vector<int> on(m);
        rep(i, m) { //各電球について
            vector<int> cnt(n);
            for(int j = 0; j < n; ++j) { //ビットを取り出す位置j
                if(bit & (1 << j)) { // j番目のビットが立っているなら
                    rep(k, s[i].size()) { // sにつながっているか確認
                        if(s[i][k] == j + 1)
                            cnt[i] += 1;
                    }
                }
            }
            // onのスイッチの数によって点灯
            if(cnt[i] % 2 == p[i]) {
                on[i] = 1;
            }
        }
        //全て点灯なら++
        if(accumulate(on.begin(), on.end(), 0) == m) {
            ans++;
        }
        //cout << accumulate(on.begin(), on.end(), 0) << endl;
    }

    cout << ans << endl;
    return 0;
}