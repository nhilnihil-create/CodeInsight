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
    vl a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vl b;
    for (int i = 1; i < n; ++i) {
        if (a[i] <= a[i - 1]) {
            b.push_back(a[i]);
        }
    }
    if (b.size() == 0) {
        cout << 1 << "\n";
        return 0;
    }
    ll ng      = 1;
    ll ok      = n;
    auto check = [&](ll mid) {
        vector<pii> v;
        v.emplace_back(-1, -1);
        bool ret = true;
        for (int i = 0; i < b.size(); ++i) {
            int m = b[i];
            while (v.back().first > m)
                v.pop_back();
            while (v.back().first == m && v.back().second == mid - 1)
                v.pop_back(), --m;
            if (m == v.back().first)
                ++v.back().second;
            else if (m)
                v.emplace_back(m, 1);
            else {
                ret = false;
                break;
            }
        }
        return ret;
    };
    while (ok - ng > 1) {
        ll mid = (ok + ng) / 2;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }
    cout << ok << endl;
    return 0;
}