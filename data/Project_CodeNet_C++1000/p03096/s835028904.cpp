#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

int main() {
    ll n;
    cin >> n;
    vector<ll> c(1);
    cin >> c[0];
    for (ll i = 1;i < n;++i) {
        ll ci;
        cin >> ci;
        if (c.back() != ci)c.push_back(ci);
    }
    n = c.size();
    map<ll, ll> m;
    m.insert({ c[0],1 });
    vector<ll> dp(n, 0);
    dp[0] = 1;
    for (ll i = 1;i < n;++i) {
        dp[i] = (dp[i - 1] + m[c[i]]) % mod;
        m[c[i]] = dp[i];
    }
    cout << dp.back() << endl;
}