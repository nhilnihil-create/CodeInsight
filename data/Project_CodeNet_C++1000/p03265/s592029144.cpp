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
    vector<int> x1(2);
    vector<int> x2(2);
    cin >> x1[0] >> x1[1] >> x2[0] >> x2[1];
    int x_sa = x1[0] - x2[0];
    int y_sa = x2[1] - x1[1];

    vector<int> x3(2);
    x3[0] = x2[0] - y_sa;
    x3[1] = x2[1] - x_sa;

    vector<int> x4(2);
    x4[0] = x3[0] + x_sa;
    x4[1] = x3[1] - y_sa;

    cout << x3[0] << " " << x3[1] << " " << x4[0] << " " << x4[1] << endl;
    return 0;
}
