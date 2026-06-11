// 7/12
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;

    vector<ll> x(N), y(N), h(N);
    rep(i, N) cin >> x[i] >> y[i] >> h[i];

    ll H;

    for (int cx = 0; cx <= 100; cx++) {
        for (int cy = 0; cy <= 100; cy++) {
            bool ok = true;

            set<ll> s;
            set<ll> t;

            // H = abs(x[0] - cx) + abs(y[0] - cy) + h[0];
            // H = max(H, 0LL);

            for (int i = 0; i < N; i++) {
                // if (h[i] == 0) continue;
                // ll now = abs(x[i] - cx) + abs(y[i] - cy) + h[i];
                // if (H != now) {
                //     ok = false;
                //     break;
                // }
                if (h[i] > 0) {
                    s.insert(abs(x[i] - cx) + abs(y[i] - cy) + h[i]);
                } else {
                    t.insert(abs(x[i] - cx) + abs(y[i] - cy) + h[i]);
                }
            }

            // if (ok && H >= 1) {
            if (s.size() == 1) {
                H = *s.begin();
                // cout << cx << " " << cy << " " << H << endl;
                // return 0;
                bool ok = true;
                rep(i, N) {
                    ll now = max(H - abs(x[i] - cx) - abs(y[i] - cy), 0LL);
                    if (now != h[i]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    cout << cx << " " << cy << " " << H << endl;
                    return 0;
                }
            }
        }
    }
}