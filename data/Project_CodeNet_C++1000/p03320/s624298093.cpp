#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...) 0
#endif

ll s(ll n) {
    ll b = 0;
    while (n > 0) {
        b += n % 10;
        n /= 10;
    }
    return b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll k;
    cin >> k;
    ll n = 1;
    vector<ll> x = {1};
    rep(i, 0, 15) x.emplace_back(*x.rbegin() * 10ll);
    debug(x);

    while (k--) {
        cout << n << endl;
        double mn = 1e18;
        int j = 0;
        rep(i, 0, 16) {
            double a = (double)(n + x[i]) / s(n + x[i]);
            if (a < mn) {
                j = i;
                mn = a;
            }
        }
        n += x[j];
    }

    return 0;
}