#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vt<int> a(n);
    for (int &i : a) cin >> i;
    sort(all(a));

    int idx = 0;
    for (int i = 1; i < n - 1; i++) {
        if (abs(a.back() - a[i] * 2) < abs(a.back() - a[idx] * 2)) {
            idx = i;
        }
    }

    cout << a.back() << ' ' << a[idx];
}
