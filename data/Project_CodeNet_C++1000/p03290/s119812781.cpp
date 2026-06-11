#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
using ll = long long;
const int inf = 1e9; //1(1倍)e(指数)9(10^9)
int main() {
    int D;
    ll G;
    cin >> D >> G;
    
    vector<ll> p(D), c(D);
    rep(i, D) cin >> p[i] >> c[i];

    ll res = inf;
    for (int bit = 0; bit < (1 << D); ++bit) {
        ll sum = 0;
        ll num = 0;
        rep(i, D)  {
            if (bit & (1 << i)) {
                sum += c[i] + p[i] * 100 * (i + 1);
                num += p[i];
            }
        }
        if (sum >= G) {
            res = min(res, num);
        }
        
        else {
            for (int i = D - 1; i >= 0; --i) {
                if (bit & (1 << i)) continue;
                for (int j = 0; j < p[i]; ++j) {
                    if (sum >= G) break;
                    sum += 100 * (i + 1);
                    ++num;
                }
            }
            res = min(res, num);
        }
    }
    cout << res << endl;
    return 0;
}