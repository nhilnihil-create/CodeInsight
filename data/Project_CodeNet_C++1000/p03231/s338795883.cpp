#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
    ll n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    ll ans = lcm(n, m);
    ll g = gcd(n, m);
    for (ll k = 0; k < g; k++) {
        if (s[k * n / g] != t[k * m / g]) {
            ans = -1;
        }
    }
    cout << ans << endl;
}