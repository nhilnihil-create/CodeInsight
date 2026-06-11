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
    vector<pll> dt(n);
    for (int i = 0; i < n; ++i) {
        cin >> dt[i].second >> dt[i].first;
    }
    sort(dt.begin(), dt.end(), greater<pll>());
    priority_queue<pll> pq;
    priority_queue<pll, vector<pll>, greater<pll>> pq2;
    map<ll, int> cnt;
    ll val = 0;
    ll sum  = 0;
    for (int i = 0; i < k; ++i) {
        sum += dt[i].first;
        if (cnt[dt[i].second] == 0) {
            cnt[dt[i].second]++;
            val++;
        } else {
            pq2.push(dt[i]);
        }
    }
    for (int i = k; i < n; ++i) {
        pq.push(dt[i]);
    }
    sum += val * val;
    ll ret = sum;
    while (!pq.empty() && !pq2.empty()) {
        auto q = pq.top();
        pq.pop();
        if (cnt[q.second] != 0)
            continue;
        cnt[q.second]++;
        auto p = pq2.top();
        pq2.pop();
        sum -= val * val;
        val++;
        sum += val * val;
        sum += q.first - p.first;
        chmax(ret, sum);
    }
    cout << ret << "\n";
    return 0;
}