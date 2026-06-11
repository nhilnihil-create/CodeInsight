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
vector<vector<int>> G;
ll dfs(int i, int p, ll d) {
    ll res = d;
    for (auto &e : G[i]) {
        if (e == p) {
            continue;
        }
        res += dfs(e, i, d + 1LL);
    }
    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<P> v;
    map<ll, int> mp;
    for (int i = 0; i < n; i++) {
        ll d;
        cin >> d;
        v.push_back(P(d, i));
        mp[d] = i;
    }
    sort(all(v));
    reverse(all(v));
    vector<ll> sz(n, 1);
    vector<P> res;
    G.resize(n);
    for (int i = 0; i < n - 1; i++) {
        ll d = v[i].first, id = v[i].second;
        if (mp.count(d - (n - 2LL * sz[id]))) {
            int to = mp[d - (n - 2LL * sz[id])];
            G[to].push_back(id);
            sz[to] += sz[id];
            res.push_back(P(to, id));
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    if (dfs(v[n - 1].second, -1, 0) != v[n - 1].first) {
        cout << -1 << endl;
        return 0;
    }
    for (auto &p : res) {
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }
}
