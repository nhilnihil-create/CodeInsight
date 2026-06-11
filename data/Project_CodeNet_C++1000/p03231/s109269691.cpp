#include<iostream>
using namespace std;
typedef long long ll;

ll calc_gcd(ll a, ll b) {
    if (a % b == 0) return b;
    else return calc_gcd(b, a % b);
}

ll calc_lcm(ll a, ll b) {
    return a * b / calc_gcd(a, b);
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll n, m;
    string s, t;
    cin >> n >> m >> s >> t;

    ll ans = calc_lcm(n, m);
    ll gcd = calc_gcd(n, m);
    bool ok = true;
    for (int i = 0; i < gcd; i++) {
        int s_idx = i * n / gcd;
        int t_idx = i * m / gcd;
        if (s[s_idx] != t[t_idx]) ok = false;
    }

    if (ok) cout << ans << endl;
    else cout << -1 << endl;
}