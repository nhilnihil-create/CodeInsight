#include <bits/stdc++.h>
using namespace std;

void chmin (int &x, int a) {
    x = min(x, a);
}

const int inf = 1e9 + 13;

signed main () {
    int n, k;
    cin >> n >> k;
    vector < int > a(n);
    for (int &x: a)
        cin >> x;
    int ans = inf;
    for (int i = 0; i + k <= n; ++i) 
        chmin(ans, a[i + k - 1] - a[i] + abs(a[i]));
    for (int i = n - 1; i - k + 1 >= 0; --i)
        chmin(ans, a[i] - a[i - k + 1] + abs(a[i]));
    cout << ans << '\n';
}
