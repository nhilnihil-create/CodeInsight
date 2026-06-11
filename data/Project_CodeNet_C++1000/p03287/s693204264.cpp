#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

int main() {
    int n;  ll m;   cin >> n >> m;
    vector<ll> a(n), s(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[i+1] = (s[i] + a[i]) % m;
    }

    map<ll, ll> mp;
    for (int i = 0; i <= n; i++) {
        mp[s[i]]++;
    }

    ll ans = 0;
    for (auto ite: mp) {
        ll c = ite.second;
        ans += c * (c-1) / 2;
    }

    cout << ans << endl;
    return 0;
}