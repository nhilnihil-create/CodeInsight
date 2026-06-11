#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    double t[n], v[n];
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    double l_min[n + 1], r_min[n + 1];
    l_min[0] = 0;
    r_min[n] = 0;
    for (int i = 0; i < n; i++) {
        l_min[i + 1] = min(l_min[i] + t[i], v[i]);
        r_min[n - i - 1] = min(r_min[n - i] + t[n - i - 1], v[n - i - 1]);
    }
    double vs[n + 1];
    for (int i = 0; i <= n; i++) {
        vs[i] = min(l_min[i], r_min[i]);
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
        double peek_x = (t[i] - vs[i] + vs[i + 1]) / 2, peek_y = (t[i] + vs[i] + vs[i + 1]) / 2;
        ans += (peek_y + vs[i]) * peek_x + (peek_y + vs[i + 1]) * (t[i] - peek_x);
        double v_t = max(0.0, peek_y - v[i]);
        ans -= v_t * v_t * 2;
    }
    ans /= 2;
    cout << fixed << setprecision(4) << ans << endl;
    return 0;
}
