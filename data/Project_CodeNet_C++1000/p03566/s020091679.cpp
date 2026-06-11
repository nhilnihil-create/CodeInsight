#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> t(n + 2), v(n + 2), u(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    u = v;
    debug(u);
    for (int i = 1; i <= n; i++) {
        u[i] = min(u[i], u[i + 1]);
        for (int j = i; j >= 1; j--) {
            if (abs(u[j] - u[j - 1]) <= t[j]) {
                break;
            }
            if (u[j - 1] + t[j] < u[j]) {
                u[j] = u[j - 1] + t[j];
                break;
            }
            u[j - 1] = u[j] + t[j];
        }
    }
    debug(u);
    double ans = 0;
    for (int i = 1; i <= n; i++) {
        int v0 = u[i - 1];
        int v1 = u[i];
        if (v0 > v1) {
            swap(v0, v1);
        }
        double mv = min((double)v[i], (t[i] + v0 + v1) * 0.5);
        ans += t[i] * v0;
        ans += (mv - v0) * (mv - v0) * 0.5;
        ans += (mv - v0 + v1 - v0) * (mv - v1) * 0.5;
        ans += (mv - v0) * max(0.0, t[i] - (mv - v1) - (mv - v0));
    }
    cout << fixed << setprecision(10);
    cout << ans << '\n';
    return 0;
}