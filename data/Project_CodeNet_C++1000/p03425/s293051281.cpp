# include <bits/stdc++.h>
# define rep(i, n) for (ll i = 0; i < (n); i++)
# define reps(i, n) for (ll i = 1; i <= (n); i++)
# define foreps(i, m, n) for (ll i = (m); i < (n); i++)
# define len(x) ((int)(x).size())
# define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
const long long mod = 1e9 + 7;
const long long inf = 1e18;

vector<ll> p = { 0, 0, 0, 0, 0, 0, 1, 1, 1, 2 };
vector<ll> q = { 1, 1, 1, 2, 2, 3, 2, 2, 3, 3 };
vector<ll> r = { 2, 3, 4, 3, 4, 4, 3, 4, 4, 4 };

int main() {
    ll n; cin >> n;
    vector<ll> march(5, 0);
    rep(i, n) {
        string s; cin >> s;
        if (s[0] == 'M') ++march[0];
        else if (s[0] == 'A') ++march[1];
        else if (s[0] == 'R') ++march[2];
        else if (s[0] == 'C') ++march[3];
        else if (s[0] == 'H') ++march[4];
    }

    ll ans = 0;
    rep(i, 10) {
        ans += march[p[i]] * march[q[i]] * march[r[i]];
    }
    cout << ans << endl;
}