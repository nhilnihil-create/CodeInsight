#include "bits/stdc++.h"
using namespace std;

const long long INF = 5e18;

void solve() {
    int N;
    cin >> N;
    vector<double> t(N + 1), v(N);
    for (int i = 0; i < N; i++) {
        cin >> t.at(i + 1);
        t.at(i + 1) += t.at(i);
    }
    for (int i = 0; i < N; i++) cin >> v.at(i);
    double ans = 0, l, r;
    for (double i = 0; i < t.at(N); i += 0.5) {
        l = min(i, t.at(N) - i);
        r = min(i + 0.5, t.at(N) - 0.5 - i);
        for (int j = 0; j < N; j++) {
            if (i + 0.5 <= t.at(j)) {
                l = min(l, v.at(j) + (t.at(j) - i));
                r = min(r, v.at(j) + (t.at(j) - 0.5 - i));
            } else if (i >= t.at(j + 1)) {
                l = min(l, v.at(j) + (i - t.at(j + 1)));
                r = min(r, v.at(j) + (i + 0.5 - t.at(j + 1)));
            } else {
                l = min(l, v.at(j));
                r = min(r, v.at(j));
            }
        }
        ans += (l + r) * 0.25;
    }
    cout << fixed << ans << endl;
    return;
}

int main() {
    solve();
}