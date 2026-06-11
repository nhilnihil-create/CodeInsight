#include "bits/stdc++.h"
#define rep(i, j) for (int i = 0; i < j; i++)
using namespace std;
using ll = long long;

int gcd(int x, int y);

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
    string s;
    cin >> s;
    
    if (s[0] != 'A') {
        cout << "WA" << endl;
        return 0;
    }
    int num = 0;
    for (int i = 2; i <= s.size() - 2; i++) {
        if (s[i] == 'C')
            num++;
    }
    
    if (num == 0 || num >= 2) {
        cout << "WA" << endl;
        return 0;
    }

    rep(i, s.size()) {
        if (i == 0) continue;
        if (s[i] == 'C' && i >= 2 && i <= s.size() - 2) continue;
        if (s[i] >= 'A' && s[i] <= 'Z') {
            cout << "WA" << endl;
            return 0;
        }
    }

    cout << "AC" << endl;
    return 0;
}

/*���C�u�����ő����*/
//���[�O���b�h�̌ݏ��@
int gcd(int x, int y) {
    int num[3];
    num[0] = (x > y) ? x : y;
    num[1] = (x <= y) ? x : y;
    num[2] = num[0] % num[1];

    while (num[2]) {
        num[0] = num[1];
        num[1] = num[2];
        num[2] = num[0] % num[1];
    }

    return num[1];
}