#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Rational {
    long long num;
    long long den;
    bool operator<=(const Rational& r) const { return compare(r) <= 0; }
    inline long long compare(const Rational& r) const {
        long long ln = num, ld = den, rn = r.num, rd = r.den;
        if ( ld < 0 ) ln = -ln, ld = -ld;
        if ( rd < 0 ) rn = -rn, rd = -rd;
        return ln * rd - ld * rn;
    }
};

ll solve() {
    ll K;
    cin >> K;

    auto S = [](ll n) -> ll {
        ll r = 0;
        while ( n > 0 ) {
            r += n % 10;
            n /= 10;
        }
        return r;
    };
    vector<ll> pow(18);
    pow[0] = 1;
    for ( int i = 1; i < 18; i++ ) pow[i] = pow[i-1] * 10;
    vector<ll> ans;
    ll n = 1e15;
    Rational m{0, 1};
    while ( n > 0 ) {
        for ( ll d = 0; pow[d] <= n ; d++ ) {
            ll x = n - pow[d];
            Rational xr{S(x), x};
            if ( m <= xr ) {
                m = xr;
                n = x;
                if ( n <= 0 ) break;
                ans.push_back(n);
                break;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    for ( int i = 0; i < K; i++ ) {
        cout << ans[i] << "\n";
    }
    return 0;
}

int main() {
    solve();
    return 0;
}