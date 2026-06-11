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

double digsum(string k) {
    double ret = 0;
    for (int i = 0; i < int(k.size()); ++i) {
        ret += k[i] - '0';
    }
    return ret;
}

int main() {
    ll k;
    cin >> k;
    set<pair<ll, double>> snuke;
    for (int i = 1; i <= 1000 * 15; ++i) {
        int dig    = i / 1000;
        string num = to_string(i % 1000);
        if (num == "0")
            continue;
        for (int j = 0; j < dig; ++j) {
            num += "9";
        }
        snuke.emplace(stoll(num), stod(num) / digsum(num));
    }
    double curr = 1e16;
    deque<ll> ret;
    for (auto it = snuke.rbegin(); it != snuke.rend(); it = next(it)) {
        if (curr == it->second || chmin(curr, it->second))
            ret.push_front(it->first);
    }
    for (int i = 0; i < k; ++i) {
        cout << ret[i] << "\n";
    }
    return 0;
}