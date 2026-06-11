#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N;
vector<ll> a, b, c;
int main() {
    cin >> N;
    a.resize(N);
    b.resize(N);
    c.resize(N);
    rep(i, N) cin >> a[i] >> b[i] >> c[i];

    // 中心座標決め打ち
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            set<ll> set_h;
            bool lim = false;
            // h が 1以上のケース
            for (int k = 0; k < N; k++) {
                if (c[k] <= 0) continue;
                ll tmp_h = c[k] + abs(a[k] - i) + abs(b[k] - j);
                if (tmp_h < 1) {
                    lim = true;
                }
                set_h.insert(tmp_h);
            }
            if (lim) continue;
            if (set_h.size() != 1) continue;

            ll h = *set_h.begin();
            ll cont = false;
            // h が 0のケース
            for (int k = 0; k < N; k++) {
                if (c[k] > 0) continue;
                ll tmp_h = max(h - abs(a[k] - i) - abs(b[k] - j), 0LL); 
                if (tmp_h != 0) {
                    cont = true;
                }
            }
            if (cont) continue;
            // if (i == 2 && j == 2) {
            //     cout << lim << endl;
            //     cout << set_h.size() << " " << *set_h.begin() << endl;
            // }
            // cout << *set_h.begin() << endl;
             cout << i << " " << j << " " << *set_h.begin() << endl;
            return 0;
        }
    }
}