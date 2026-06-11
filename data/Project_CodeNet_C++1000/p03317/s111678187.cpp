#include "bits/stdc++.h"
#define rep(i, j) for (int i = 0; i < j; i++)
using namespace std;
using ll = long long;

const int INF = 1001001001;

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
    int n, k;
    int pla;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        if (a[i] == 1)
            pla = i;
    }
    int ans = 0;

    ans = (n - 1) / (k - 1);
    if ((n - 1) % (k - 1) != 0)
        ans++;
    cout << ans << endl;
    return 0;
}