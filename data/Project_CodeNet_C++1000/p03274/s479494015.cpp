#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, k; cin >> n >> k;
    vector<ll> x(n);
    ll ans = 1e9;
    for (ll i = 0; i < n; ++i) 
        cin >> x[i];
    for (ll i = 0; i < n - k + 1; ++i) {
        ll l = x[i], h = x[i + k - 1];
        if (l < 0 && h > 0) ans = min(ans, 2 * min(abs(l), abs(h)) + max(abs(l), abs(h)));
        else ans = min(ans, max(abs(l), abs(h)));
    }
    if (n == 1) ans = abs(x[0]);
    cout << ans << "\n";
}