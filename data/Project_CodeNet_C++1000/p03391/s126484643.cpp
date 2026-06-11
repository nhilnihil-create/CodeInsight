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
    int n;
    cin >> n;
    vl a(n), b(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        sum += a[i];
    }
    bool ok  = true;
    ll ret   = 0;
    ll gezan = INF;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i])
            ok = false;
        if (a[i] > b[i]) {
            chmin(gezan, b[i]);
        }
    }
    if (ok)
        cout << 0 << "\n";
    else
        cout << sum - gezan << "\n";
    return 0;
}