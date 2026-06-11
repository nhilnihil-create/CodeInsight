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
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
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
template <typename T>
vector<T> Dijkstra(int s, vector<vector<pair<int, T>>>& g) {
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>>
        que;
    int n = sz(g);
    vector<T> d(n);
    rep(i, n) d[i] = LINF;
    d[s] = 0;
    que.push(make_pair(0LL, s));
    while (!que.empty()) {
        pair<T, int> p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (auto e : g[v]) {
            if (chmin(d[e.first], d[v] + e.second)) {
                que.push(make_pair(d[e.first], e.first));
            }
        }
    }
    return d;
}
int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, ll>>> g(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].emplace_back(b, 1ll);
        g[b].emplace_back(a, 1ll);
    }
    auto d = Dijkstra(0, g);
    int v = max_element(all(d)) - d.begin();
    auto e = Dijkstra(v, g);
    ll x = *max_element(all(e)) + 1;
    vector<bool> dp(1001001, 0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 0;
    for (int i = 1; i < x; i++) {
        if (!dp[i]) {
            dp[i + 1] = 1;
            dp[i + 2] = 1;
        }
    }
    cout << (dp[x] ? "First" : "Second") << endl;
}