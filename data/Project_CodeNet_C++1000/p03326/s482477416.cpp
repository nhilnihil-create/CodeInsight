#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<lint>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int n, m;
    cin >> n >> m;
    vec x(n), y(n), z(n);
    rep(i, n) cin >> x[i] >> y[i] >> z[i];

    lint res = 0;

    rep(f, 1 << 3) {
        vec s(n);
        rep(i, n) {
            if (f & 1) s[i] += -x[i];
            else s[i] += x[i];

            if ((f >> 1) & 1) s[i] += -y[i];
            else s[i] += y[i];

            if ((f >> 2) & 1) s[i] += -z[i];
            else s[i] += z[i];
        }

        vec ord(n);
        rep(i, n) ord[i] = i;

        sort(all(ord), [&](const int& i, const int& j) { return s[i] > s[j]; });

        lint tmp = 0;
        lint x_s = 0, y_s = 0, z_s = 0;

        rep(i, m) {
            x_s += x[ord[i]];
            y_s += y[ord[i]];
            z_s += z[ord[i]];
        }

        tmp = abs(x_s) + abs(y_s) + abs(z_s);

        res = max(res, tmp);
    }

    cout << res << endl;
    return 0;
}