#include "bits/stdc++.h"
#define REP(i, n) for(int i = 0; i < int(n); i++)
#define FOR(i,n,m) for(int i = int(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 6;
const ll LLINF = 1e18 + 1;

template<int mod>
struct mint {
private:
    long long x;
public:
    mint(long long x = 0) :x(x%mod) {}
    mint(std::string s) {
        long long z = 0;
        REP(i, s.size()) {
            z *= 10;
            z += s[i] - '0';
            z %= mod;
        }
        this->x = z;
    }
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }
    friend std::ostream& operator<<(std::ostream& os, const mint& n) {
        return os << n.x;
    }
    bool operator==(const mint a) const {
        return this->x == a.x;
    }
};

//pow
template<typename T, typename U>
T pow(T k, U n, T unity = 1) {
    while (n > 0) {
        if (n & 1) {
            unity *= k;
        }
        k *= k;
        n >>= 1;
    }
    return unity;
}

int main() {
    string s; cin >> s;
    int n = s.size();
    const int mod = 1e9 + 7;
    vector<mint<mod>> a(n+1,0), b(n+1,0), c(n+1,0);
    int cnt = 0;
    REP(i, n) {
        if (s[i] == 'A') {
            a[i + 1] = a[i] + pow(mint<mod>(3), cnt);
            b[i + 1] = b[i];
            c[i + 1] = c[i];
        }
        else if (s[i] == 'B') {
            a[i + 1] = a[i];
            b[i + 1] = a[i] + b[i];
            c[i + 1] = c[i];
        }
        else if (s[i] == 'C') {
            a[i + 1] = a[i];
            b[i + 1] = b[i];
            c[i + 1] = c[i] + b[i];
        }
        else {
            a[i + 1] = a[i] * 3 + pow(mint<mod>(3), cnt);
            b[i + 1] = a[i] + b[i] * 3;
            c[i + 1] = b[i] + c[i] * 3;
            cnt++;
        }
    }
    cout << c[n] << endl;
    return 0;
}