#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) { return b ? gcd(b,a % b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b;}

int main() {
    ll n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    ll l = lcm(n, m);
    ll p = l / n;
    ll q = l / m;
    ll l2 = lcm(p, q);
    for (int i = 0; i < l / l2; ++i) {
        if (s[l2 * i / p] == t[l2 * i / q]) continue;
        cout << -1 << endl;
        return 0;
    }
    cout << l << endl;
}
