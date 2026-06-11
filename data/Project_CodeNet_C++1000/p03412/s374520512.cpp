#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...) 0
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, ans = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    for (int s = 28; s >= 0; s--) {
        int bt = 1 << s;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int mn = bt - a[i];
            int tmp = lower_bound(b.begin(), b.end(), mn + bt) - lower_bound(b.begin(), b.end(), mn);
            tmp += b.end() - lower_bound(b.begin(), b.end(), mn + bt * 2);
            cnt ^= tmp & 1;
            a[i] &= bt - 1;
        }
        ans += bt * cnt;
        if (!s) break;
        for (int i = 0; i < n; i++) {
            b[i] &= bt - 1;
        }
        sort(b.begin(), b.end());
    }
    cout << ans << endl;
    return 0;
}