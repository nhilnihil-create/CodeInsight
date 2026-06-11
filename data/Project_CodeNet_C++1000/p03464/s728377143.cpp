#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll mi_ans = 2, ma_ans = 2;
    for (int i = n - 1; i >= 0; --i) {
        ll mi = ((mi_ans + a[i] - 1) / a[i]) * a[i];
        ll ma = (ma_ans / a[i]) * a[i] + a[i] - 1;

        if (mi > ma_ans || ma < mi_ans) {
            cout << -1 << endl;
            return 0;
        }
        mi_ans = mi;
        ma_ans = ma;
    }
    cout << mi_ans << " " << ma_ans << endl;

    return 0;
}