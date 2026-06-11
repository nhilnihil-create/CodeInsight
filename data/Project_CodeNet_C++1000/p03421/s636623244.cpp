#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    if (a + b > n + 1 || a * b < n) {
        cout << -1 << endl;
        return 0;
    }

    vector<ll> ans;
    for (ll i = b; i > 0; i--) {
        ans.push_back(i);
    }
    if (a != 1) {
        ll k = (n - b) / (a - 1);
        ll p = (n - b) % (a - 1);
        ll q = a - 1 - p;
        rep(i, p) {
            ll cursz = ans.size();
            rep(j, k + 1) {
                ans.push_back(cursz + k + 1 - j);
            }
        }
        rep(i, q) {
            ll cursz = ans.size();
            rep(j, k) {
                ans.push_back(cursz + k - j);
            }
        }
    }
    rep(i, ans.size()) {
        cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
    }
}