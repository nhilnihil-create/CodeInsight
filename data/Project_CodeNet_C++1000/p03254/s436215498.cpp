#include "bits/stdc++.h"
#define rep(i, j) for (int i = 0; i < j; i++)
using namespace std;
using ll = long long;

/*struct mint {
    ll x; // typedef long long ll;
    mint(ll x = 0) :x((x% mod + mod) % mod) {}
    mint operator-() const { return mint(-x); }
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }
    mint operator+(const mint a) const { return mint(*this) += a; }
    mint operator-(const mint a) const { return mint(*this) -= a; }
    mint operator*(const mint a) const { return mint(*this) *= a; }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const { return pow(mod - 2); }
    mint& operator/=(const mint a) { return *this *= a.inv(); }
    mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream& operator>>(istream & is, const mint & a) { return is >> a.x; }
ostream& operator<<(ostream & os, const mint & a) { return os << a.x; }*/

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());

    int i;
    for (i = 0; i < n - 1; i++) {
        if (x >= a[i])
            x -= a[i];
        else
            break;
    }

    if (x == a[n - 1])
        i++;

    cout << i << endl;
    return 0;
}
