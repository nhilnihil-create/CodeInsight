#include <bits/stdc++.h>
using namespace std;

signed main () {
    int n;
    cin >> n;
    vector < int > a(n);
    bool pos = 0, neg = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos = pos | (a[i] >= 0);
        neg = neg | (a[i] <= 0);
    }
    if (pos && neg) {
        int mx = max_element(a.begin(), a.end()) - a.begin(), mn = min_element(a.begin(), a.end()) - a.begin();
        if (a[mx] > abs(a[mn])) {
            cout << 2 * n - 1 << '\n'; 
            for (int i = 1; i <= n; ++i)
                cout << mx + 1 << ' ' << i << '\n';
            for (int i = 1; i <= n - 1; ++i)
                cout << i << ' ' << i + 1 << '\n';
        }
        else {
            cout << 2 * n - 1 << '\n'; 
            for (int i = 1; i <= n; ++i)
                cout << mn + 1 << ' ' << i << '\n';
            for (int i = n; i >= 2; --i)
                cout << i << ' ' << i - 1 << '\n';
        }
    }
    else if (pos) {
        cout << n - 1 << '\n';
        for (int i = 1; i <= n - 1; ++i)
            cout << i << ' ' << i + 1 << '\n';
    }
    else if (neg) {
        cout << n - 1 << '\n';
        for (int i = n; i >= 2; --i)
            cout << i << ' ' << i - 1 << '\n';
    }
}
