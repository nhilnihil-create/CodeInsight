#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e18;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    vector <int> a(t);
    for (int& it : a) {
        cin >> it;
    }
    sort(a.begin(), a.end());
    int n = a[t - 1], m = a[0];
    for (int i = 1; i + 1 < t; ++i) {
        if (abs(n - 2 * a[i]) < abs(n - 2 * m)) {
            m = a[i];
        }
    }
    cout << n << " " << m << "\n";
    return 0;
}