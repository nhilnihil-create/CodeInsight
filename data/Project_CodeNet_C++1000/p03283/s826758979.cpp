#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define ddrep(i, n) for (int i = n; i > 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define ssrep(i, s, t) for (int i = s; i <= t; ++i)

#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

#define chmax(x, y) (x = max(x, y))
#define chmin(x, y) (x = min(x, y))

using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using ld = long double;

template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "{";
    rep(i, (int)v.size()) {
        if (i)
            os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

template <typename T, size_t S> void printArray(const T (&array)[S]) {
    for (auto val : array)
        std::cout << val << ", ";
    std::cout << "\n";
}

const int mod = 1e9 + 7;
const int inf = 1e9 + 5;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << std::setprecision(10);

    int n, m, q; std::cin >> n >> m >> q;
    vvi s(n, vi(n));
    map<int, int> cnt;
    rep(i, m) {
        int l, r; std::cin >> l >> r;
        --l, --r;
        s[l][r]++;
    }
    rep(i, n) rep(j, n) {
        if (j-1 >= 0) s[i][j] += s[i][j-1];
    }
    rep(i, q) {
        int p, q; std::cin >> p >> q;
        --p, --q;
        int ans = 0;
        srep(i, p, q+1) {
            ans += s[i][q] - (p-1 < 0 ? 0 : s[i][p-1]);
        }
        std::cout << ans << "\n";
    }
}
