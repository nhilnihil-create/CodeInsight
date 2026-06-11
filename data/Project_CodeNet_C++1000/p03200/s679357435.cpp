#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

int main()
{
    string s;
    cin >> s;
    int w = 0;
    ll ans = 0;
    rep(i, s.size()) {
        if(s[i] == 'W') {
            w++;
            ans += i;
        }
    }
    ans -= (ll) w * (w - 1) / 2;
    cout << ans << endl;
    return 0;
}
