#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    ll n, k; cin >> n >> k;

    vector<ll> v(n);
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
    }

    ll ans = 0;
    for (ll i = 1; i <= k; ++i) {
        priority_queue<ll, vector<ll>, greater<ll>> q;
        for (ll l = 0; l <= i; ++l) {
            if (i >= n) {
                for (ll j = 0; j < n; ++j) {
                    q.push(v[j]);
                }
            } else {
                for (ll j = 0; j < l; ++j) {
                    q.push(v[j]);
                }

                for (ll r = 0; r < i - l; ++r) {
                    q.push(v[n - 1 - r]);
                }
            }

            for (ll j = 0; j < k - i; ++j) {
                if (q.empty()) break;

                ll t = q.top();
                if (t >= 0) break;
                q.pop();
            }

            ll sum = 0;
            if (!q.empty()) {
                while (!q.empty()) {
                    ll t = q.top();
                    sum += t;
                    q.pop();
                }
            }

            ans = max(ans, sum);
        }
    }

    cout << ans << endl;
}