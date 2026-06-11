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

int main() {
    ll n;
    cin >> n;
    vl c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    vl d(1);
    d[0] = c[0];
    for (int i = 1; i < n; ++i) {
        if (c[i] != d.back())
            d.push_back(c[i]);
    }
    map<int, vector<ll>> cnt;
    vector<ll> dp(d.size(), 0);
    dp[0] = 1;
    cnt[d[0]].push_back(1);
    for (int i = 1; i < d.size(); ++i) {
        dp[i] = dp[i - 1];
        if (cnt[d[i]].size() != 0)
            dp[i] = (dp[i] + cnt[d[i]].back()) % MOD;

        if (cnt[d[i]].size() == 0)
            cnt[d[i]].push_back(dp[i - 1]);
        else
            cnt[d[i]].push_back((cnt[d[i]].back() + dp[i - 1]) % MOD);
    }
    cout << dp[d.size() - 1] << "\n";
    return 0;
}