#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    ll n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    vector<pair<char, ll>> h ={ { 'M', 0 }, { 'A', 0 },
        { 'R', 0 }, { 'C', 0 }, { 'H', 0 } };
    // set<string> ss;
    rep(i, n) {
        rep(j, h.size()) {
            if (s[i][0] == h[j].first) {
                h[j].second++;
                // ss.insert(s[i]);
                // && !ss.count(s[i])
            }
        }
    }
    ll ans = 0;
    for (ll i = 0; i <= 4; i++) {
        for (ll j = i+1; j <= 4; j++) {
            for (ll k = j+1; k <= 4; k++) {
                ans += h[i].second * h[j].second * h[k].second;
            }
        }
    }
    cout << ans << endl;
    return 0;
}