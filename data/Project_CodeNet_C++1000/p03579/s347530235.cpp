#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr int Mod = 998244353;
constexpr int mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

vector<vector<int>> G;
vector<int> color;

bool dfs(int v, int c) {
    color[v] = c;
    for(int u : G[v]) {
        if(color[u] == c) return false;
        if(color[u] == 0 && !dfs(u, -c)) return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;
    G.resize(n);
    color.resize(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if(dfs(0, 1)) {
        ll a = 0, b = 0;
        rep(i, n)(color[i] == 1 ? a : b)++;
        cout << a * b - m << endl;
    } else
        cout << n * (n - 1) / 2 - m << endl;

    return 0;
}