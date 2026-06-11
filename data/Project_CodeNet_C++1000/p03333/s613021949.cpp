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
    vector<pii> lr, rl;
    for (ll i = 0; i < n; ++i) {
        ll l, r;
        cin >> l >> r;
        lr.emplace_back(l, r);
        rl.emplace_back(r, l);
    }
    sort(rl.begin(), rl.end());
    sort(lr.begin(), lr.end(), greater<pii>());
    // from right
    ll retR = 0;
    ll curr = 0;
    ll odd  = n % 2;
    for (ll i = 0; i < n / 2 + odd; ++i) {
        retR += max(0ll, lr[i].first - curr);
        if (lr[i].first > curr)
            curr = lr[i].first;
        retR += max(0ll, curr - rl[i].first);
        if (rl[i].first < curr)
            curr = rl[i].first;
    }
    retR += abs(curr);

    // from left
    ll retL = 0;
    curr     = 0;
    for (ll i = 0; i < n / 2 + odd; ++i) {
        retL += max(0ll, curr - rl[i].first);
        if (rl[i].first < curr)
            curr = rl[i].first;
        retL += max(0ll, lr[i].first - curr);
        if (lr[i].first > curr)
            curr = lr[i].first;
    }
    retL += abs(curr);
    cout << max(retR, retL) << "\n";
    return 0;
}