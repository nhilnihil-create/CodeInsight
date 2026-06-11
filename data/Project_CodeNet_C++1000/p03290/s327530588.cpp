#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    int d, g; cin >> d >> g;
    vector<int> p(d);
    vector<int> c(d);
    for (int i = 0; i < d; ++i) {
        cin >> p[i] >> c[i];
    }

    int ans = INF;

    for (int bit = 0; bit < (1 << d); ++bit) {
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < d; ++i) {
            if (bit & (1 << i)) {
                sum += 100 * (i + 1) * p[i] + c[i];
                cnt += p[i];
            }
        }

        if (sum >= g) {
            ans = min(ans, cnt);
        } else {
            for (int i = d - 1; i >= 0; --i) {
                if (!(bit & (1 << i))) {
                    bool brk = false;
                    for (int j = 1; j < p[i]; ++j) {
                        sum += 100 * (i + 1);
                        cnt++;
                        if (sum >= g) {
                            brk = true;
                            break;
                        }
                    }
                    if (brk) break;
                }
            }

            if (sum >= g) {
                ans = min(ans, cnt);
            }
        }
    }

    cout << ans << endl;
}