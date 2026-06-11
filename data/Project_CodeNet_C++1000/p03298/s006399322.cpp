#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int main(){
    ll n; cin >> n;
    string s; cin >> s;
    vector<int> a(2 * n);
    rep(i, 2 * n) a[i] = (int)(s[i] - 'a') + 1;
    vector<int> check(26,0);
    rep(i, 2 * n) {
        if (i < n) check[a[i]-1]++;
        else check[a[i]-1]--;
    }
    rep(i, 26) if (check[i]) { cout << 0 << "\n"; return 0; }

    map<pair<ll,ll>,ll> mp;
    rep(i, 1ll<<n) {
        ll c1 = 0, c2 = 0;
        rep(j, n) {
            if (i & 1ll<<j) { c1 *= 10007; c1 += a[j]; }
            else { c2 *= 10007; c2 += a[j]; }
        }
        mp[make_pair(c1,c2)]++;
    }

    ll ans = 0;
    rep(i, 1ll<<n) {
        ll c1 = 0, c2 = 0;
        rep(j, n) {
            if (i & 1ll<<j) { c1 *= 10007; c1 += a[n+n-1-j]; }
            else { c2 *= 10007; c2 += a[n+n-1-j]; }
        }
        ans += mp[make_pair(c1,c2)];
    }

    cout << ans << endl;
    return 0;
}