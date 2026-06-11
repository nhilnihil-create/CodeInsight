#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    ll n, X;

    cin >> n >> X;
    vector<ll> x(n + 1);
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= n; ++i) x[i] += x[i - 1];

    ll min_e = numeric_limits<ll>::max();
    for (ll k = n; 1 <= k; --k) {
        ll sum = 0, id = 1;
        for (ll r = n, l; 1 <= r && (sum + k * X) < min_e; r = l - 1) {
            l = max(1ll, r - k + 1);
            sum += (id == 1 ? 5 : 2 * id + 1) * (x[r] - x[l - 1]);
            ++id;
        }
        min_e = min(min_e, sum + k * X);
    }

    cout << min_e + n * X << endl;

    return 0;
}
