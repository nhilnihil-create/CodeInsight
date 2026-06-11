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
    int h, w, n;
    cin >> h >> w >> n;
    vector<pii> yx;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        yx.emplace_back(y, x - y);
    }
    sort(yx.begin(), yx.end());
    int top = 0;
    int col = 0;
    int ret = h;
    for (int i = 0; i < n; ++i) {
        if (yx[i].second < top)
            continue;
        if (yx[i].first != col) {
            col = yx[i].first;
        }
        if (top == yx[i].second)
            top++;
        if (yx[i].second > top)
            chmin(ret, yx[i].first + yx[i].second - 1);
    }
    cout << ret << "\n";
    return 0;
}