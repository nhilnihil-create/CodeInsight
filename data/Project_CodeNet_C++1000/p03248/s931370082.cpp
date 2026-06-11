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
    if (s[0] == '0' || s[n - 1] == '1') {
        cout << -1 << "\n";
        return 0;
    }
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - i - 2]) {
            cout << -1 << "\n";
            return 0;
        }
    }
    int curr = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i-1] == '1') {
            cout << curr << " " << i+1 << "\n";
            curr = i+1;
        } else {
            cout << curr << " " << i+1 << "\n";
        }
    }
    return 0;
}