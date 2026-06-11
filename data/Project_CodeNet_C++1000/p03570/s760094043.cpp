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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> cnt(1 << 26, 1 << 29);
    cnt[0]  = 0;
    ll curr = 0;
    for (int i = 0; i < n; ++i) {
        int t = 1 << 29;
        curr ^= 1 << (s[i] - 'a');
        for (int j = 0; j < 27; ++j) {
            ll temp = curr ^ (1 << j);
            if (j == 26)
                temp = curr;
            chmin(t, 1 + cnt[temp]);
        }
        chmin(cnt[curr], t);
    }
    if (curr == 0)
        cout << 1 << "\n";
    else
        cout << cnt[curr] << "\n";
    return 0;
}