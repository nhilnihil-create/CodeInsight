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
    int n, k, q;
    cin >> n >> k >> q;
    vl a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vl sorted = a;
    sort(sorted.begin(), sorted.end());
    set<ll> unused;
    ll ret = INF;
    for (int i = 0; i < n; ++i) {
        vl mins;
        vl temp;
        for (int j = 0; j < n; ++j) {
            if (unused.count(a[j]) == 0) {
                temp.push_back(a[j]);
            } else if (!temp.empty()) {
                sort(temp.begin(), temp.end());
                for (int m = 0; m < int(temp.size()) + 1 - k; ++m) {
                    mins.push_back(temp[m]);
                }
                temp.clear();
            }
        }
        if (!temp.empty()) {
            sort(temp.begin(), temp.end());
            for (int m = 0; m < int(temp.size()) + 1 - k; ++m) {
                mins.push_back(temp[m]);
            }
        }
        if (mins.size() >= q) {
            sort(mins.begin(), mins.end());
            chmin(ret, mins[q - 1] - mins[0]);
        }
        unused.insert(sorted[i]);
    }
    cout << ret << "\n";
    return 0;
}
