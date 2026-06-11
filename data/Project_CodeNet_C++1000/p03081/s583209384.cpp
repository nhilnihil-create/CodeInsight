#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // std::ifstream in("input.txt");
    // std::cin.rdbuf(in.rdbuf());
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<pair<char, char>> td(q);
    rep(i, q) cin >> td[i].first >> td[i].second;
    s = '*' + s + '*';
    ll l = 0, r = n + 1;
    while((l + 1) < r) {
        ll m = (l + r) / 2;
        ll pos = m;
        rep(i, q) {
            if (td[i].first != s[pos]) continue;
            if (td[i].second == 'L') pos--;
            else pos++;
        }
        if (pos == 0) l = m;
        else r = m;
    }
    ll delcnt = l;
    l = 0, r = n + 1;
    while((l + 1) < r) {
        ll m = (l + r) / 2;
        ll pos = m;
        rep(i, q) {
            if (td[i].first != s[pos]) continue;
            if (td[i].second == 'L') pos--;
            else pos++;
        }
        if (pos == (n + 1)) r = m;
        else l = m;
    }
    delcnt += (n + 1 - r);
    cout << (n - delcnt) << endl;
    return 0;
}
