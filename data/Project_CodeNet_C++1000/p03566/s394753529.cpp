#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 100 + 5;
int n;
int t[N], l[N], m[N], r[N];
double ans;
int cur;

double f(int i) {
    double lm = l[i];
    double rm = r[i];
    double ll = min(l[i], r[i]), rr = m[i];
    double t1, t2;
    while (ll + 1e-8 < rr) {
        double mm = (ll + rr) / 2;
        t1 = abs(mm - lm);
        t2 = abs(mm - rm);
        if (t1 + t2 <= t[i]) {
            ll = mm;
        } else {
            rr = mm - 1e-8;
        }
    }
    // cout << lm << ' ' << m[i] << ' ' << rm << " # " << ll << endl;
    t1 = abs(ll - lm);
    t2 = abs(ll - rm);
    return (t[i] - t1 - t2) * ll + (ll + l[i]) / 2 * t1 + (ll + r[i]) / 2 * t2;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
        l[i] = r[i] = m[i];
    }
    r[n - 1] = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (i < n - 1) {
            r[i] = min(r[i], l[i + 1]);
        }
        l[i] = min(l[i], r[i] + t[i]);
    }
    l[0] = 0;
    for (int i = 0; i < n; ++i) {
        if (i > 0)
            l[i] = min(l[i], r[i - 1]);
        r[i] = min(r[i], l[i] + t[i]);
    }
    for (int i = 0; i < n; ++i) {
        ans += f(i);
    }
    cout << ans << endl;
    return 0;
}
