//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <x86intrin.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define V vector
template <typename T> bool chmin(T &a, const T &b) {if(a > b){a = b; return true;} return false;}
template <typename T> bool chmax(T &a, const T &b) {if(a < b){a = b; return true;} return false;}
template<typename A, size_t N, typename T> void Fill (A (&array)[N], const T & val) {fill ((T*)array, (T*)(array+N), val);}
V<int> dx = {-1, 1,  0, 0, -1, -1,  1, 1};
V<int> dy = { 0, 0, -1, 1, -1,  1, -1, 1};

V<int> color(1e5+1, 0);
V<V<P>> to(1e5+1);

void dfs (int v, int c) {
    color[v] = c;
    for (P p : to[v]) {
        int nv = p.first, a = p.second;
        if (color[nv] == 0) dfs(nv, c*a);
    }
}

int main () {
    int n; cin >> n;
    rep(i, n-1) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        if (w % 2 == 0) {
            to[u].emplace_back(v, 1); to[v].emplace_back(u, 1);
        }
        else {
            to[u].emplace_back(v, -1); to[v].emplace_back(u, -1);
        }
    }
    dfs(0, 1);
    rep(i, n) {
        if (color[i] == 1) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}