#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

using ll = long long;
using ul = unsigned long long;
using ld = long double;
ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    string a, b, c;
    cin >> a >> b >> c;

    set<char> s[n];
    rep(i, n) {
        s[i].insert(a[i]);
        s[i].insert(b[i]);
        s[i].insert(c[i]);
    }

    ll ans = 0;
    rep(i, n) { ans += s[i].size() - 1; }

    cout << ans << endl;
    return 0;
}

