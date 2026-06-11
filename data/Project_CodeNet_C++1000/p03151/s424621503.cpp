#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
using lint = long long;

int main() {
    int n;
    cin >> n;

    vector<lint> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    lint ans = 0, tot = 0;
    vector<lint> vt;
    for (int i = 0; i < n; i++) {
        if (a[i] >= b[i])
            vt.push_back(a[i] - b[i]);
        else {
            tot += (b[i] - a[i]);
            ans++;
        }
    }

    sort(vt.begin(), vt.end(), greater<>());
    for (long long x : vt) {
        if (tot > 0) {
            tot -= x;
            ans++;
        }
    }

    if (tot > 0) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
