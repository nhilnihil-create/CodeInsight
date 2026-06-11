#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(s) (int)s.size()

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n), y(n);
    vector<int> xs(n), ys(n);
    rep(i, 0, n) {
        cin >> x[i] >> y[i];
        xs[i] = x[i]; ys[i] = y[i];
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    long long area = 1LL * (xs.back() - xs[0]) * (ys.back() - ys[0]);
    rep(lx, 0, n) rep(rx, lx, n) rep(ly, 0, n) rep(ry, ly, n) {
        int ps = 0;
        rep(i, 0, n) if (xs[lx] <= x[i] && x[i] <= xs[rx] && ys[ly] <= y[i] && y[i] <= ys[ry])
            ++ps;
        if (ps >= k) area = min(area, 1LL * (xs[rx] - xs[lx]) * (ys[ry] - ys[ly]));
    }
    cout << area << '\n';
}