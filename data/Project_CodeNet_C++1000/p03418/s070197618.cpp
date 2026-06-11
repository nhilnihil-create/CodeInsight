#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    int n, k; cin >> n >> k;

    ll ans = 0;

    for (int i = 1; i <= n; ++i) {
        if (i <= k) {
            continue;
        }

        ans += (i - k) * (n / i);
        if (n % i != 0) {
            for (int j = 1; j <= (n % i); ++j) {
                if (j >= k) {
                    ++ans;
                }
            }
        }
    }

    cout << ans << endl;
}