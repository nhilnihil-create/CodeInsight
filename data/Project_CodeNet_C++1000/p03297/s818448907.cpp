#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"

bool solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a < b) return false;
    if (d < b) return false;
    if (c >= (b - 1)) return true;
    ll g = __gcd(b, d);
    ll v = (b - a % g + (g - 1)) / g * g + a % g - g;
    return !(v > c); 
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll t;
    cin >> t;
    rep(i, t) cout << (solve() ? "Yes" : "No") << endl;
    return 0;
}
