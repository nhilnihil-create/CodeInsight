#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; long long c; cin >> n >> c;
    vector<long long> x(n), sum(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        sum[i+1] = sum[i] + x[i];
    }
    long long ans = 1e18;
    for (long long k = n; k > 0; k--) {
        long long t = n;
        long long cur = (k+n) * c;
        for (int i = 0; t > 0; i++) {
            long long s = min(k, t);
            long long y = (i == 0 ? 5 : (2*i+3));
            cur += (sum[t] - sum[t-s]) * y;
            t -= s;
            if (ans < cur) break;
        }
        ans = min(ans, cur);
    }
    cout << ans << endl;
    return 0;
}