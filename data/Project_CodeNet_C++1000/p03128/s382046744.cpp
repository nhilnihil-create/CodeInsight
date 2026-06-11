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
    int n, m;
    cin >> n >> m;
    vi a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vi matches = {-1, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    map<int, int> ma;
    map<int, vi> ma2;
    for (auto &aa : a) {
        ma2[matches[aa]].push_back(aa);
    }
    for (auto &p : ma2) {
        sort(p.second.begin(), p.second.end(), greater<int>());
        ma[p.first] = p.second.front();
    }
    vi dp(n + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (auto &p : ma) {
            if (i - p.first >= 0) {
                chmax(dp[i], dp[i - p.first] + 1);
            }
        }
    }
    sort(a.begin(), a.end(), greater<int>());
    string ret = "";
    int curr   = n;
    bool proc  = false;
    while (curr != 0) {
        proc = false;
        for (auto &aa : a) {
            if (curr - matches[aa] >= 0 && dp[curr - matches[aa]] + 1 == dp[curr]) {
                ret += to_string(aa);
                proc = true;
                curr -= matches[aa];
                break;
            }
        }
        if (!proc)
            curr++;
    }
    cout << ret << "\n";
    return 0;
}