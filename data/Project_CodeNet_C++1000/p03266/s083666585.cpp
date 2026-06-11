#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    ll n, k; cin >> n >> k;

    vector<ll> cnt(k, 0);
    for (ll i = 1; i <= n; ++i) {
        cnt[i % k]++;
    }

    ll ans = 0;
    // a % k で全探索
    for (ll a = 0; a < k; ++a) {
        ll b = (k - a) % k;
        ll c = (k - a) % k;

        if ((b + c) % k != 0) {
            continue;
        }

        ans += cnt[a] * cnt[b] * cnt[c];
    }

    cout << ans << endl;
}