#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;

int main() {
    string s;
    int d, g;
    cin >> d >> g;
    pair<int, int> p[d];
    rep(i, d) cin >> p[i].first >> p[i].second;

    int ans = 999999;
    int n = d;
    for (int bit = 0; bit < (1 << n); bit++) {
        int sum = 0;
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) {
                sum += 100 * (i + 1) * p[i].first + p[i].second;
                c += p[i].first;
            }
        }
        if (sum < g) {
            for (int i = n - 1; i >= 0; i--) {
                if (!(bit & (1 << i))) {
                    rep(j, p[i].first) {
                        sum += 100 * (i + 1);
                        c++;
                        if (sum >= g) {
                            break;
                        }
                    }
                }
                if (sum >= g) {
                    break;
                }
            }
        }
        ans = min(ans, c);
    }
    cout << ans << endl;
    return 0;
}
