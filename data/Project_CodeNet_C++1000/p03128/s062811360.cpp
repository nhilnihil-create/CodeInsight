#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(unique(all(x)), x.end());
typedef long long ll;
typedef complex<double> Complex;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
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

bool CHMAX(string &x, string y) {
    if (y[0] != '#' &&
        (x == "#" || sz(x) < sz(y) || (sz(x) == sz(y) && x < y))) {
        x = y;
        return true;
    }
    return false;
}
vector<string> memo(10010);
vector<int> f = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
vector<int> a;
string dp(int i) {
    if (i < 0) {
        return "#";
    }
    if (i == 0) {
        return "";
    }
    if (memo[i] != "-1") {
        return memo[i];
    }
    string ret = "#";
    for (int x : a) {
        CHMAX(ret, dp(i - f[x]) + to_string(x));
    }
    return memo[i] = ret;
}

int main() {
    int n, m;
    cin >> n >> m;
    a.resize(m);
    rep(i, m) cin >> a[i];
    rep(i, 10010) memo[i] = "-1";
    cout << dp(n) << endl;
}