#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m, ans;
map<ll, ll> cnt;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    ++cnt[0];
    ll cur = 0;

    for (int i = 0; i < n; ++i) {
        ll a; cin >> a;
        cur += a;
        cur %= m;
        ans += cnt[cur]++;
    }
    cout << ans;
}
