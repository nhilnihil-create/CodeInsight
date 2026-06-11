#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s; cin >> s;
    ll ans = 1LL << 60;
    for (ll i = 0; i < s.size()-1; i++) {
        if (s[i] != s[i+1]) {
            ll val = max(i+1, (ll)s.size()-i-1LL);
            ans = min(ans, val);
        }
    }
    if (ans != 1LL << 60) cout << ans << endl;
    else cout << s.size() << endl;
}