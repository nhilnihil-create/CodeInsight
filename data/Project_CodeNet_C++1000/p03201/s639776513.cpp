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
    ll a[n];
    rep(i, n) { cin >> a[i]; }
    map<ll, ll> m;

    rep(i, n) { m[-a[i]]++; }

    ll ans = 0;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        ll num = -(iter->first);

        ll x = 1;
        while (x <= num) {
            x *= 2;
        }
        ll pair = x - num;

        if (pair == num) {
            ans += iter->second / 2;
            iter->second %= 2;
            continue;
        }

        while (iter->second != 0) {
            if (m[-pair] > 0) {
                m[-pair]--;
                ans++;
                iter->second--;
            } else {
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}

