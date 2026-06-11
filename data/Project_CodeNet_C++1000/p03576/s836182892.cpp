#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> x(N), y(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    ll ans = 8e18;
    for (int a = 0; a < N; a++) {
        for (int b = a + 1; b < N; b++) {
            for (int c = 0; c < N; c++) {
                for (int d = c + 1; d < N; d++) {
                    ll mx = min(x[a], x[b]);
                    ll Mx = max(x[a], x[b]);
                    ll my = min(y[c], y[d]);
                    ll My = max(y[c], y[d]);

                    int cnt = 0;
                    for (int i = 0; i < N; i++) {
                        if (mx <= x[i] && x[i] <= Mx && my <= y[i] && y[i] <= My) {
                            cnt++;
                        }
                    }
                    if (cnt >= K) {
                        ans = min(ans, (Mx - mx) * (My - my));
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
