#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
constexpr ll INF = (1LL << 30) - 1LL;
constexpr ll LINF = (1LL << 60) - 1LL;
constexpr double eps = 1e-9;
constexpr ll MOD = 1000000007LL;
template <typename T>
bool chmin(T& a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
};
template <typename T>
bool chmax(T& a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
};
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
    for(int i = 0; i < v.size(); i++) {
        os << v[i] << (i + 1 == v.size() ? "\n" : " ");
    }
    return os;
}
template <typename T>
vector<T> make_v(size_t a) {
    return vector<T>(a);
}
template <typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type fill_v(T& t, const V& v) {
    t = v;
}
template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type fill_v(T& t, const V& v) {
    for(auto& e : t) {
        fill_v(e, v);
    }
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> p(n + 10);
    auto co = make_v<ll>(n + 10, n + 10);  // j番目までの、iより大きい要素数
    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        p[k] = i;
        for(int j = 1; j < k; j++) {
            co[j][i]++;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            co[i][j] += co[i][j - 1];
        }
    }
    auto dp = make_v<ll>(n + 10, n + 10);
    fill_v(dp, LINF);
    dp[0][0] = 0;
    ll ans = LINF;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(j < p[i] - 1) {
                chmin(dp[i][j], dp[i - 1][j] + b);
                chmin(dp[i][p[i]], dp[i - 1][j] + (co[i][p[i]] - co[i][j]) * a);
            } else {
                chmin(dp[i][j], dp[i - 1][j]);
            }
            if(i == n) {
                chmin(ans, dp[i][j]);
            }
        }
    }
    cout << ans << endl;
}