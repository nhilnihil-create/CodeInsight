#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n; cin >> n;
    vector<double> t(n), v(n);
    for (auto& x: t) {
        cin >> x;
    }
    for (auto& x: v) {
        cin >> x;
    }
    t.emplace_back(0);
    v.emplace_back(0);
    double res = 0;
    double cur = 0;
    for (int i = 0; i < n; i++) {
        double out = v[i];
        double dt = 0;
        for (int j = i+1; j <= n; j++) {
            out = min(out, v[j] + dt);
            dt += t[j];
        }
        double inc = min({v[i]-cur, t[i], (out+t[i]-cur)/2.0});
        double dec = max(0.0, cur+inc - out);
        double cons = t[i] - inc - dec;
        res += (cur*2.+inc)*inc/2.;
        cur += inc;
        res += cur * cons;
        res += (cur*2.-dec)*dec/2.;
        cur -= dec;
    }
    cout << fixed << setprecision(5) << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    cout << endl;
}
