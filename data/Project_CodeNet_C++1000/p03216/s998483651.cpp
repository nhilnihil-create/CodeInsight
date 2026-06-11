#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
//#include "library/debug.cpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> d, m, c;
    vector<ll> a(n);
    rep(i, 0, n) {
        if (s[i] == 'D') d.emplace_back(i);
        if (s[i] == 'M') m.emplace_back(i), a[i]++;
        if (s[i] == 'C') c.emplace_back(i);
    }
    rep(i, 1, n) a[i] += a[i - 1];
    int q;
    cin >> q;
    while (q--) {
        int k, j = -1, l = -1;
        cin >> k;
        ll ans = 0, sum = 0;
        rep(i, 0, d.size()) {
            while (c[j + 1] - d[i] < k && j + 1 < c.size()) {
                j++;
                sum += a[c[j]];
            }
            while (c[l + 1] - d[i] < 0 && l + 1 < c.size()) {
                l++;
                sum -= a[c[l]];
            }
            if (j != -1) {
                ans += sum - a[d[i]] * (j - l);
            }
        }
        cout << ans << endl;
    }
    return 0;
}