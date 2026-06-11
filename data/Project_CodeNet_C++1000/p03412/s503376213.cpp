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
    vl a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ret = 0;
    for (int i = 0; i < 29; ++i) {
        vl c = a, d = b;
        for (int j = 0; j < n; ++j) {
            c[j] %= 1 << (i + 1);
            d[j] %= 1 << (i + 1);
        }
        sort(c.begin(), c.end());
        sort(d.begin(), d.end());
        if (i == 0) {
            int oddc = 0, oddd = 0;
            for (int j = 0; j < n; ++j) {
                if (c[j] == 1)
                    oddc++;
                if (d[j] == 1)
                    oddd++;
            }
            ll t = oddc * (n - oddd) + (n - oddc) * oddd;
            ret += t % 2;
        } else {
            ll t = 0;
            for (int j = 0; j < n; ++j) {
                auto l1 = lower_bound(d.begin(), d.end(), (1 << i) - c[j]);
                auto u1 = lower_bound(d.begin(), d.end(), (1 << (i + 1)) - c[j]);
                auto l2 = lower_bound(d.begin(), d.end(), (1 << (i + 1)) + (1 << i) - c[j]);
                auto u2 = lower_bound(d.begin(), d.end(), (1 << (i + 2)) - c[j]);
                t += u1 - l1 + u2 - l2;
            }
            ret += t % 2 * (1 << i);
        }
    }
    cout << ret << "\n";
    return 0;
}