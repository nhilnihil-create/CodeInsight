#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

ll gcd(ll a, ll b) {
    if(a % b == 0) return b;
    else return(gcd(b, a % b));
}

int main()
{
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    string t;
    cin >> t;
    ll l = n * m / gcd(n, m);
    ll x = l / gcd(n, m);
    bool ok = true;
    for(ll i = 0; i * x + 1 <= l; i++) {
        ll snum = i * x * n / l;
        ll tnum = i * x * m / l;
        if(s[snum] != t[tnum]) ok = false;
    }
    if(ok) cout << l << endl;
    else cout << -1 << endl;
    return 0;
}
