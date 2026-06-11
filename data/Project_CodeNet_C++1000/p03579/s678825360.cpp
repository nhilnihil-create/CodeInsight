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

V<V<int>> to(1e5+1);
V<int> color(1e5+1, 0);

bool dfs (int v, int c) {
    color[v] = c;
    for (int nv : to[v]) {
        if (color[nv] == c) return false;
        if (color[nv] == 0 && !dfs(nv, -c)) return false;
    }
    return true;
}

int main () {
    int n, m; cin >> n >> m;
    rep(i, m) {
        int a, b; cin >> a >> b; a--; b--;
        to[a].emplace_back(b); to[b].emplace_back(a);
    }
    ll ans;
    if (dfs(0, 1)) {//二部グラフなら
        ll a = 0, b = 0;
        rep(i, n) {
            if (color[i] == 1) a++;
            else b++;
        }
        ans = a * b - m;
    }
    else {
        ans = (ll) n * (n-1) / 2 - m;
    }
    cout << ans << endl;
    return 0;
}