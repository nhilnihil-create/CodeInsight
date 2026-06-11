#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    // const ll n = 2 * 1e5, X = 1e9;
    // cout << n << ' ' << X << '\n';
    // for (int i = n - 1; 0 <= i; --i) {
    //     cout << X - i << (i == 0 ? '\n' : ' ');
    // }

    ll n, X;

    cin >> n >> X;
    vector<ll> x(n + 1);
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= n; ++i) x[i] += x[i - 1];

    ll min_e = numeric_limits<ll>::max();
    for (ll k = 1; k <= n; ++k) {
        ll sum = 0, id = (n + k - 1) / k;
        ll l = 1, r = (n % k == 0 ? k : n % k);
        while (l <= n) {
            ll mul = (id == 1 ? 5 : 2 * id + 1);
            sum += mul * (x[r] - x[l - 1]);
            l = r + 1;
            r += k;
            --id;
        }
        if (0 <= sum + k * X)
            min_e = min(min_e, sum + k * X);
    }

    cout << min_e + n * X << endl;

    return 0;
}
