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
    vector<deque<int>> a(1 << n);
    for (int i = 0; i < (1 << n); ++i) {
        int aa;
        cin >> aa;
        a[i].push_back(aa);
    }
    for (int i = 1; i < (1 << n); i <<= 1) {
        for (int j = 0; j < (1 << n); ++j) {
            if ((i & j) == 0) {
                for (auto &b : a[j])
                    a[j | i].push_back(b);
                sort(a[j | i].begin(), a[j | i].end());
                while (a[j | i].size() > 2)
                    a[j | i].pop_front();
            }
        }
    }
    vi ret(1 << n, 0);
    for (int i = 1; i < (1 << n); ++i) {
        ret[i] = a[i][0] + a[i][1];
        if (i)
            chmax(ret[i], ret[i - 1]);
    }
    for (int i = 1; i < (1 << n); ++i) {
        cout << ret[i] << "\n";
    }
    return 0;
}