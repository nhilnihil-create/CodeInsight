#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
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

ll max_diff(ll a, ll b, ll c, ll d) {
    if (a < 1 || b < 1 || c < 1 || d < 1)
        return INF;
    ll maxi = max({a, b, c, d});
    ll mini = min({a, b, c, d});
    return maxi - mini;
}

int main() {
    int n;
    cin >> n;
    vl a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vl suma(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        suma[i + 1] += suma[i] + a[i];
    }
    ll ret = INF;
    for (int i = 1; i < n - 1; ++i) {
        auto bit = upper_bound(suma.begin(), suma.end(), (suma[i]) / 2);
        auto dit = upper_bound(suma.begin(), suma.end(), suma[i] + (suma[n] - suma[i]) / 2);
        for (auto &b : {bit, prev(bit), next(bit)}) {
            for (auto &d : {dit, prev(dit), next(dit)}) {
                chmin(ret, max_diff(*b, suma[i] - *b, *d - suma[i], suma[n] - *d));
            }
        }
    }
    cout << ret << "\n";
    return 0;
}