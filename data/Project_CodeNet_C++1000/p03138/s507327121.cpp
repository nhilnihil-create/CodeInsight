#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 1e5 + 5;
ll n, k, t, sum, ans;
int cnt[41];
ll benf[41][2];
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        for (int j = 0; j < 41; ++j) {
            if (t & (1LL << j)) {
                ++cnt[j];
            }
        }
    }
    ll base = 1;
    for (int i = 0; i <= 40; ++i) {
        benf[i][0] = base * cnt[i];
        benf[i][1] = base * (n - cnt[i]);
        base *= 2;
    }

    base /= 2;
    for (int i = 40; i >= 0; --i) {
        // cout << i << ' ' << cnt[i] << ' ' << benf[i][0] << ' ' << benf[i][1] << endl;
        if (benf[i][0] >= benf[i][1]) {
            ans += benf[i][0];
        } else {
            if (sum + base > k) {
                ans += benf[i][0];
            } else {
                ans += benf[i][1];
                sum += base;
            }
        }
        base /= 2;
    }
    cout << ans << endl;
    return 0;
}
