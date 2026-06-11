#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define all(v) v.begin(), v.end()
#define inputv(v, n)                                                           \
    vl v;                                                                      \
    rep(i, n) {                                                                \
        ll x;                                                                  \
        cin >> x;                                                              \
        v.push_back(x);                                                        \
    }
bool chmin(ll& a, ll& b) { if (b < a) { a = b; return 1; } return 0; }
bool chmax(ll& a, ll& b) { if (b > a) { a = b; return 1; } return 0; }
const ll INF = 999999999999999;
const ll MOD = 1000000007;
const ll MAX_N = 500010;
ll a, b, c, d, e, f, p, t, x, y, z, q, m, n, r, h, k, w, l, ans;
ll ketawa(ll n) {
    ll x = 0;
    while (n > 0) {
        x += n % 10;
        n = n / 10;
    }
    return x;
}
int main() {
    cin >> k;
    a = 1;
    b = 1;
    while (k > 0) {
        c = (b / (a * 10)+1) * a * 10 - 1;
        if (b * ketawa(c) <= (c) * ketawa(b)) {
            cout << b << endl;
            k--;
        }
        else if (b!=c) {
            a *= 10;
            b = c - a;
        }
        b += a;
    }
}
