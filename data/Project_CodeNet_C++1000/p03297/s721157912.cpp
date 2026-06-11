#include "bits/stdc++.h"
using namespace std;
using ll     = long long;
using pii    = pair<int, int>;
using pll    = pair<ll, ll>;
using vi     = vector<int>;
using vl     = vector<ll>;
using vvi    = vector<vi>;
using vvl    = vector<vl>;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}
template <class C>
void print(const C &c, std::ostream &os = std::cout) {
    std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, " "));
    os << std::endl;
}

// greatest common divisor and least common multiple
// gcd is calculated by Euclidean Algorithm
// lcm = m * n / gcd(m,n)
template <typename T = int>
T gcd(T a, T b) {
    if (a < b)
        return gcd(b, a);
    T r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

int main() {
    int t;
    cin >> t;
    vl a(t), b(t), c(t), d(t);
    for (int i = 0; i < t; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    for (int i = 0; i < t; ++i) {
        if (d[i] < b[i]) {
            cout << "No"
                 << "\n";
            continue;
        }
        if (a[i] < b[i]) {
            cout << "No"
                 << "\n";
            continue;
        }
        if (b[i] <= d[i] && c[i] >= b[i]) {
            cout << "Yes"
                 << "\n";
            continue;
        }
        a[i] %= b[i];
        ll gcdbd = gcd(b[i], d[i]);
        ll maxi = a[i] + (b[i] - 1 - a[i]) / (gcdbd) * gcdbd;
        if (maxi > c[i]) {
            cout << "No"
                 << "\n";
        } else {
            cout << "Yes"
                 << "\n";
        }
    }
    return 0;
}