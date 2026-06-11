#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

int n;
double t, a, h, tt, ans;

int main() {
    cin >> n >> t >> a;
    int ti = 1;
    cin >> h;
    tt = t - h * 0.006;
    ans = abs(a - tt);
    for (int i = 2; i <= n; ++i) {
        cin >> h;
        tt = t - h * 0.006;
        if (abs(a - tt) < ans) {
            ans = abs(a - tt);
            ti = i;
        }
    }
    cout << ti << endl;
    return 0;
}
