#include <bits/stdc++.h>
using namespace std;

using lint = long long;
#define bit(n) (lint(1) << n)
#define lb(v, n) lower_bound(v.begin(), v.end(), n)

int main() {
    int n;
    cin >> n;
    vector<lint> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    lint ans = 0;
    for (int k = 0; k < 50; k++) {
        lint m = bit(k);
        vector<lint> am(n), bm(n);
        for (int i = 0; i < n; i++) {
            am[i] = a[i] % (2 * m);
            bm[i] = b[i] % (2 * m);
        }
        sort(bm.begin(), bm.end());

        lint num = 0;
        for (int i = 0; i < n; i++) {
            num += lb(bm, 2 * m - am[i]) - lb(bm, m - am[i])
                   + lb(bm, 4 * m - am[i]) - lb(bm, 3 * m - am[i]);
        }
        ans += (num % 2) * m;
    }

    cout << ans << endl;
    return 0;
}