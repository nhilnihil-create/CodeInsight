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
    ll n;
    cin >> n;
    vl a(n);
    ll tot = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        tot += a[i];
    }
    if (n == 1) {
        cout << a[0] << "\n";
        return 0;
    }
    bitset<4000000> dp = 0;
    dp[0]              = 1;
    for (int i = 0; i < n; ++i) {
        dp |= dp << a[i];
    }
    for (int i = tot / 2 + tot % 2; i < tot; ++i) {
        if (dp[i] == 1) {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}