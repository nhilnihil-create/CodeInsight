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

vector<vector<int>> g;
ll k = 0;
vector<ll> num;
void dfs0(int now, int pre) {
    for (int nxt : g[now]) {
        if (nxt == pre) continue;
        dfs0(nxt, now);
    }
    num[now] = k;
    k++;
}
ll ans = 0;
void dfs1(int now, int pre) {
    for (int nxt : g[now]) {
        if (nxt == pre) continue;
        ans += min(num[now], num[nxt]);
        dfs1(nxt, now);
    }
}
int main() {
    int n;
    cin >> n;
    g.resize(n);
    num.resize(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<ll> c(n);
    rep(i, n) cin >> c[i];
    sort(all(c));
    dfs0(0, -1);
    rep(i, n) num[i] = c[num[i]];
    dfs1(0, -1);
    cout << ans << endl;
    rep(i, n) cout << num[i] << endl;
}