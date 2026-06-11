#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

using ll = long long;
using ul = unsigned long long;
using ld = long double;
ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    ll d[n];
    rep(i, n) { cin >> d[i]; }
    sort(d, d + n);

    bool memo[25] = {};
    memo[0] = true;
    memo[24] = true;
    rep(i, n) {
        ll num;

        if (i % 2) {
            num = d[i];
        } else {
            num = 24 - d[i];
        }
        if (memo[num]) {
            cout << 0 << endl;
            return 0;
        }
        memo[num] = true;
    }

    ll last = -mod;
    ll ans = 24;
    rep(i, 25) {
        if (memo[i]) {
            ans = min(ans, i - last);
            last = i;
        }
    }
    if (ans == 24) {
        ans = 0;
    }
    cout << ans << endl;

    return 0;
}

