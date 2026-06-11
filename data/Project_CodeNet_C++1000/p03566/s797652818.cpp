#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
constexpr ll INF = (1LL << 30) - 1LL;
constexpr ll LINF = (1LL << 60) - 1LL;
constexpr double eps = 1e-9;
constexpr ll MOD = 1000000007LL;
template <typename T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
};
template <typename T> bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
};
template <typename T> ostream &operator<<(ostream &os, vector<T> v) {
    for (int i = 0; i < v.size(); i++) {
        os << v[i] << (i + 1 == v.size() ? "\n" : " ");
    }
    return os;
}
template <typename T> vector<T> make_v(size_t a) { return vector<T>(a); }
template <typename T, typename... Ts> auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type fill_v(T &t, const V &v) {
    t = v;
}
template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type fill_v(T &t, const V &v) {
    for (auto &e : t) {
        fill_v(e, v);
    }
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> t(n), v(n);
    int en = 0;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        en += t[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<double> ub(2 * en + 1);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 2 * sum + 1; j <= 2 * (sum + t[i]); j++) {
            ub[j] = v[i];
        }
        sum += t[i];
    }
    sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 2 * (sum + t[i]) + 1; j <= 2 * en; j++) {
            chmin(ub[j], v[i] + (j - 2 * (sum + t[i])) / 2.0);
        }
        for (int j = 2 * sum; j > 0; j--) {
            chmin(ub[j], v[i] + (2 * sum - j) / 2.0);
        }
        sum += t[i];
    }
    for (int i = 1; i <= 2 * en; i++) {
        chmin(ub[i], i / 2.0);
    }
    for (int i = 2 * en; i >= 1; i--) {
        chmin(ub[i], (2 * en - i) / 2.0);
    }
    double res = 0;
    ub[0] = 0;
    for (int i = 1; i <= 2 * en; i++) {
        // cout << ub[i] << endl;
        res += (ub[i] + ub[i - 1]) / 4.0;
    }
    cout << fixed << setprecision(10) << res << endl;
}
