#include <bits/stdc++.h>
using ll = long long;
using namespace std;

constexpr int inf = 1e9;
constexpr ll linf = 5e18;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, K; cin >> n >> K;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    ll ans = linf;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    ll L = min({x[i], x[j], x[k], x[l]});
                    ll R = max({x[i], x[j], x[k], x[l]});
                    ll D = min({y[i], y[j], y[k], y[l]});
                    ll U = max({y[i], y[j], y[k], y[l]});
                    int cnt = 0;
                    for (int m = 0; m < n; m++) {
                        if (L <= x[m] && x[m] <= R && D <= y[m] && y[m] <= U) cnt++;
                    }
                    if (cnt >= K) ans = min(ans, (R - L) * (U - D));
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}