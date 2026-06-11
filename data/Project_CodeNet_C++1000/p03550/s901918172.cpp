#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, z, w;
    cin >> n >> z >> w;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = abs(a[n - 1] - w);
    if (n != 1) ans = max(ans, abs(a[n - 2] - a[n - 1]));
    cout << ans << '\n';
    return 0;
}