#include "bits/stdc++.h"
#define rep(i, j) for (int i = 0; i < j; i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;

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
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    sort(s.begin(), s.end());
    int m;
    cin >> m;
    vector<string> t(m);
    rep(i, m) cin >> t[i];
    sort(t.begin(), t.end());
    int ans = 0;
    rep(k, n) {
        int num = 0;
        rep(i, n) {
            if (s[k] == s[i])
                num++;
        }
        rep(j, m) {
            if (s[k] == t[j])
                num--;
        }
        ans = max(num, ans);
    }

    cout << ans << endl;
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