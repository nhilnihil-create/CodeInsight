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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<char> t(q), d(q);
    for (int i = 0; i < q; ++i) {
        cin >> t[i] >> d[i];
    }
    int ret = n;
    int ok = 0;
    int ng = n + 1;
    auto check = [&](int mid, bool left) {
        int pos = mid;
        int end = left ? 0 : n + 1;
        for (int i = 0; i < q; ++i) {
            if (s[pos - 1] == t[i]) {
                if (d[i] == 'L')
                    pos--;
                else
                    pos++;
            }
            if (pos == end)
                break;
        }
        return pos == end;
    };
    while (ok + 1 != ng) {
        int mid = (ok + ng) / 2;
        if (check(mid, true))
            ok = mid;
        else
            ng = mid;
    }
    ret -= ok;
    ok = n + 1;
    ng = 0;
    while (ng + 1 != ok) {
        int mid = (ok + ng) / 2;
        if (check(mid, false))
            ok = mid;
        else
            ng = mid;
    }
    ret -= (n - (ok - 1));
    cout << ret << "\n";
    return 0;
}