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
    vl a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vl acc(n, 0);
    acc[0] = a[0];
    for (int i = 1; i < n; ++i) {
        acc[i] = acc[i - 1] + a[i];
    }
    ll ret = INF;
    for (int i = 2; i < n - 1; ++i) {
        ll lsum = acc[i - 1];
        ll rsum = acc[n - 1] - acc[i - 1];
        int lm  = upper_bound(acc.begin(), acc.end(), lsum / 2) - acc.begin();
        int rm  = upper_bound(acc.begin(), acc.end(), lsum + rsum / 2) - acc.begin();
        for (int j = max(0, lm - 1); j <= min(i - 1, lm + 1); ++j) {
            for (int k = max(i, rm - 1); k <= min(n - 1, rm + 1); ++k) {
                ll llsum = acc[j];
                ll lrsum = lsum - llsum;
                ll rlsum = acc[k] - lsum;
                ll rrsum = acc[n - 1] - rlsum - lsum;
                ll maxi  = max({llsum, lrsum, rlsum, rrsum});
                ll mini  = min({llsum, lrsum, rlsum, rrsum});
                chmin(ret, maxi - mini);
            }
        }
    }
    cout << ret << "\n";
    return 0;
}