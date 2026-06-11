#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
#include <functional>

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

#define rep_(i, a_, b_, a, b, ...) for (int i = (a), i##_len = (b); i < i##_len; ++i)
#define rep(i, ...) rep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define reprev_(i, a_, b_, a, b, ...) for (int i = (b-1), i##_min = (a); i >= i##_min; --i)
#define reprev(i, ...) reprev_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

struct UnionFind {
    vector< int > data;
    UnionFind(int sz) {
        data.assign(sz, -1);
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return (false);
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return (true);
    }
    int find(int k) {
        if(data[k] < 0) return (k);
        return (data[k] = find(data[k]));
    }
    int size(int k) {
        return (-data[find(k)]);
    }
};

vector<vector<P> > graph;
vector<bool> used;
vector<ll> pl;
vector<vector<bool> > used_edge;

bool rec (int k) {
    bool ret = true;
    used[k] = true;
    rep (i, graph[k].size()) {
        if (!used_edge[k][i]) {
            int a, b; tie(a, b) = graph[k][i];
            if (used[a] && b + pl[k] != pl[a]) {
                eprintf("%d %d %d %d %d\n", b, k, pl[k], a, pl[a]);
                return false;
            }
            pl[a] = b + pl[k];
            used_edge[k][i] = true;
            if (!used[a]) {
                ret &= rec(a);
                if (!ret) return false;
            }
        }
    }
    return true;
}
int main (void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    graph.resize(n);
    rep (_, m) {
        int l, r, d; cin >> l >> r >> d; l--; r--;
        graph[l].emplace_back(r, d);
        graph[r].emplace_back(l, -d);
    }
    used.resize(n);
    pl.resize(n);
    used_edge.resize(n);
    rep (i, n) used_edge[i].resize(graph[i].size());
    bool ans = true;
    rep (i, n) {
        if (!used[i]) ans &= rec(i);
    }
    rep (i, n) eprintf("%d ", pl[i]); eprintf("\n");
    cout << (ans ? "Yes\n" : "No\n");
    return 0;
}