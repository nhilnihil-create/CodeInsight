#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template <typename T> using V = vector<T>;

constexpr int Mod = 998244353;
constexpr int mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int chokkei(const V<V<int>> &G) {
    int n = G.size();
    V<int> d(n, -1);
    d[0] = 0;
    queue<int> que;
    que.push(0);
    int v;
    while(!que.empty()) {
        v = que.front();
        que.pop();
        for(int u : G[v]) {
            if(d[u] == -1) {
                d[u] = d[v] + 1;
                que.push(u);
            }
        }
    }
    d.assign(n, -1);
    d[v] = 0;
    que.push(v);
    while(!que.empty()) {
        v = que.front();
        que.pop();
        for(int u : G[v]) {
            if(d[u] == -1) {
                d[u] = d[v] + 1;
                que.push(u);
            }
        }
    }
    return d[v];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    V<V<int>> G(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    puts(chokkei(G) % 3 == 1 ? "Second" : "First");

    return 0;
}