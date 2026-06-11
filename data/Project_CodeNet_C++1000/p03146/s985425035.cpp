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

int f(int x) {
    if (x % 2 == 0)
        return x / 2;
    else
        return 3 * x + 1;
}

int main() {
    int s;
    cin >> s;

    if (s == 2 || s == 1 || s == 4) {
        cout << 4 << endl;
        return 0;
    }

    int flag = 0;
    int cur_num = s;
    int i = 1;
    while (flag != 2) {
        int new_num = f(cur_num);
        cur_num = new_num;
        i++;
        if (new_num == 4) {
            flag++;
        }
    }
    cout << i << endl;
    return 0;
}
