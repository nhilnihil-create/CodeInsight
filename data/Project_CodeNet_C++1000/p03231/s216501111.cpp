//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

ll lcm(ll n, ll m) {
    return n*m/__gcd(n, m);
}

int main() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    ll l = lcm(n, m);
    int N = n/__gcd(n, m), M = m/__gcd(n, m);
    bool flag = true;
    for (int k = 0; k < __gcd(n, m); k++) {
        if (s[k*N] != t[k*M]) flag = false;
    }

    if (flag) cout << l << endl;
    else cout << -1 << endl;

    return 0;
}