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
    ll n, k;
    cin >> n >> k;
    ll m = n * (n + 1) / 2;
    vl a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        a[i] += a[i - 1];
    }
    ll ret = 0;
    vl b;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ll sum = a[j];
            if (i)
                sum -= a[i - 1];
            b.push_back(sum);
        }
    }
    vector<bool> use(m, true);
    for (int i = 50; i >= 0; --i) {
        ll bit  = 1LL << i;
        int cnt = 0;
        for (int j = 0; j < m; ++j) {
            if (use[j] && (bit & b[j]))
                cnt++;
        }
        if (cnt >= k)
            ret += bit;
        else
            continue;
        for (int j = 0; j < m; ++j) {
            if (!(bit & b[j]))
                use[j] = false;
        }
    }
    cout << ret << "\n";
    return 0;
}