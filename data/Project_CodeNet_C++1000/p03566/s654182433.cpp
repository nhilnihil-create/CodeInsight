#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct section {
    double l, r, y;

    double f(double x) {
        if (x < l) return y + (l - x);
        if (x > r) return y + (x - r);
        return y;
    }
};

int main() {
    int n;
    double t0 = 0, t1 = 0;
    cin >> n;
    vector<section> v(n + 2);
    for (int i = 0; i < n; i++) {
        t0 = t1;
        cin >> t1;
        t1 += t0;
        v[i + 1].l = t0, v[i + 1].r = t1;
    }
    for (int i = 0; i < n; i++) {
        double y;
        cin >> y;
        v[i + 1].y = y;
    }
    v[0].r = v[0].l = v[0].y = v[n + 1].y = 0;
    v[n + 1].r = v[n + 1].l = t1;
    double p0 = 0, p1 = 100000.0, ans = 0;
    for (double x = 0.5; x <= t1; x += 0.5) {
        for (int i = 0; i < n + 2; i++) {
            p1 = min(p1, v[i].f(x));
        }
        ans += (p1 + p0) / 4.0;
        p0 = p1;
        p1 = 100000.0;
    }
    cout << setprecision(10) << ans << endl;
    return 0;
}