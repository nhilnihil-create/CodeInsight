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
    ll n, k;
    cin >> n >> k;
    ll a[n];
    rep(i, n) { cin >> a[i]; }

    ll ans = 0;

    repd(d, -1, 50) {

        if (d != -1 && !(k & (1LL << d)))
            continue;

        ll temp = 0;

        repd(e, 0, 50) {
            ll mask = 1LL << e;
            ll num = 0;
            rep(i, n) {
                if (a[i] & mask) {
                    num++;
                }
            }
            if (e > d) {
                if (k & mask) {
                    temp += mask * (n - num);
                } else {
                    temp += mask * num;
                }
            } else if (e == d) {
                temp += mask * num;
            } else {
                temp += mask * max(num, n - num);
            }
        }
        ans = max(ans, temp);
    }

    cout << ans << endl;
    return 0;
}

