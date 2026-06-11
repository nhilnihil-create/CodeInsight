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
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int ret = 0;
    for (int a = 0; a < n; ++a) {
        // for (int b = 0; b < n; ++b) {
        int b = 0;
        auto t = s;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                t[(i + a) % n][(j + b) % n] = s[i][j];
            }
        }
        bool ok = true;
        [&] {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (t[i][j] != t[j][i]) {
                        ok = false;
                        return;
                    }
                }
            }
        }();
        if (ok)
            ret++;
        //}
    }
    ret *= n;
    cout << ret << "\n";
    return 0;
}