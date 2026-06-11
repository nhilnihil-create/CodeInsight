#include <bits/stdc++.h>
using namespace std;

signed main () {
    int n, h;
    cin >> n >> h;
    vector < int > a(n), b(n);
    for (int i = 0; i < n; ++i) 
        cin >> a[i] >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    while (h && !b.empty() && b.back() >= a.back()) {
        h = max(h - b.back(), 0);
        b.pop_back();
        ++ans;
    }
    ans += (h + a.back() - 1) / a.back();
    cout << ans << '\n';
}
