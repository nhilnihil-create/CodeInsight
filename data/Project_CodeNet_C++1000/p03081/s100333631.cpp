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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    n += 2;
    s = "a" + s + "a";
    vector<char> t(q), d(q);
    for (int i = 0; i < q; ++i) {
        cin >> t[i] >> d[i];
    }
    auto checkl = [&](ll mid) {
        for (int i = 0; i < q; ++i) {
            if (s[mid] == t[i]) {
                if (d[i] == 'L')
                    mid--;
                else
                    mid++;
            }
        }
        return mid == 0;
    };
    ll ok = 0;
    ll ng = n - 1;
    while (abs(ok - ng) != 1) {
        ll mid = (ng + ok) / 2;
        if (checkl(mid))
            ok = mid;
        else
            ng = mid;
    }
    auto checkr = [&](ll mid) {
        for (int i = 0; i < q; ++i) {
            if (s[mid] == t[i]) {
                if (d[i] == 'L')
                    mid--;
                else
                    mid++;
            }
        }
        return mid == n - 1;
    };
    ll okr = n - 1;
    ll ngr = 0;
    while (abs(okr - ngr) != 1) {
        ll mid = (ngr + okr) / 2;
        if (checkr(mid))
            okr = mid;
        else
            ngr = mid;
    }

    cout << okr - ok - 1 << "\n";
    return 0;
}