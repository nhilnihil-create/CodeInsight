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

int main() {
    int l;
    cin >> l;
    ll twoes = 1;
    ll nt    = 0;
    while (1 << (nt + 1) <= l) {
        nt++;
    }
    nt--;
    vi a, b, c;
    // 0 to 1 << (i+1) - 1
    for (int i = 0; i <= nt; ++i) {
        a.push_back(i);
        b.push_back(i + 1);
        c.push_back(0);
        a.push_back(i);
        b.push_back(i + 1);
        c.push_back(1 << i);
    }
    // 1 << (i+1) to l - 1
    for (int i = nt; i >= 0; --i) {
        if (l - (1 << (nt + 1)) >= 1 << (i)) {
            a.push_back(i);
            b.push_back(nt + 1);
            c.push_back(l - (1 << (i)));
            l -= (1 << (i));
        }
    }
    cout << nt + 2 << " " << a.size() << "\n";
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] + 1 << " " << b[i] + 1 << " " << c[i] << "\n";
    }
    return 0;
}