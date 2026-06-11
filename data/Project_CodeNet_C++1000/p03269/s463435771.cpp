#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(std::unique(all(x)), x.end());
typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
const double PI = acos(-1);
using namespace std;
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main() {
    int l;
    cin >> l;
    int n;
    rrep(i, 25) {
        if (l & (1 << i)) {
            n = i + 1;
            break;
        }
    }

    int m = 0;
    int total = 0;
    vector<tuple<int, int, int>> ans;
    for (int i = 1; i < n; i++) {
        ans.emplace_back(i, i + 1, 0);
        ans.emplace_back(i, i + 1, (1 << (i - 1)));
        m += 2;
        total += (1 << (i - 1));
    }

    int now = l - 1;
    for (int i = 1; i < n; i++) {
        if (l & (1 << (i - 1))) {
            ans.emplace_back(i, n, now - (1 << (i - 1)) + 1);
            now -= (1 << (i - 1));
            m++;
        }
    }

    cout << n << " " << m << endl;
    for (auto t : ans) {
        int u, v, w;
        tie(u, v, w) = t;
        cout << u << " " << v << " " << w << endl;
    }
}
