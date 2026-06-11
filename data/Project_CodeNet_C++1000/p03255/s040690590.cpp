#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<long> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    vector<long> ps(n + 1);
    for (int i = 0; i < n; i++) {
        ps[i + 1] = ps[i] + x[i];
    }
    long res = LONG_MAX;
    for (int k = 1; k <= n; k++) {
        int i = n;
        long s = 0;
        int c = 0;
        while (i > 0) {
            int j = max(i - k, 0);
            long y = (3 + c * 2);
            if (c == 0) y += 2;
            s += (ps[i] - ps[j]) * y;
            if (s > 1e17) s = 1e17;
            c++;
            i = j;
        }
        s += 1ll * (k + n) * q;
        res = min(res, s);
    }
    cout << res << "\n";

    return 0;
}
