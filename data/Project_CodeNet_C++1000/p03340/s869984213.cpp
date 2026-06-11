//E
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0 && (i == 0 || a[i - 1] != 0)) {
            l[i]++;
        } else if (i != 0 && a[i - 1] == 0 && a[i] != 0) {
            l[i]--;
        }
    }
    for (int i = 1; i < n; ++i) {
        l[i] += l[i - 1];
    }
    for (int i = n - 2; i >= 0; --i) {
        if (l[i] != 0) l[i] += l[i + 1];
    }
    /*for (auto it : l) {
        cout << it << " ";
    }
    cout << "\n";*/
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int mask = 0, sm = 0, j = 0;
        while (i + j < n && (mask ^ a[i + j]) == sm + a[i + j]) {
            if (l[i + j] == 0) ans++;
            else ans += l[i + j];
            //ans++;
            sm += a[i + j];
            mask ^= a[i + j];
            if (l[i + j] == 0) j++;
            else j += l[i + j];
            //j++;
        }
        //cout << ans << "\n";
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
