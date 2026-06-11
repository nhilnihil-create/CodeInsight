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

#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define repp(i, m, n) for(int i = m, i##_len = (n); i < i##_len; ++i)
#define reprev(i, n) for(int i = (n-1LL); i >= 0; --i)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

vector<bool> used;
vector<vector<int> > graph, graph_rev;
vector<int> topology;
void dfs (int st) {
    if (used[st]) return;
    used[st] = true;
    for (int i : graph[st]) {
        eprintf("%d->%d\n", st, i);
        graph_rev[i].push_back(st);
        dfs(i);
    }
    // parent[st] = par;
    topology.push_back(st);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    used.resize(n); graph.resize(n); graph_rev.resize(n);
    rep (i, n - 1 + m) {
        int a, b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        // graph_rev[b].push_back(a);
    }
    rep (i, n) dfs(i);
    for (int i : topology) eprintf("%d ", i); eprintf("\n");
    for (auto i : graph_rev) {
        eprintf("("); for (int j : i) eprintf("%d,", j); eprintf(")");
    } eprintf("\n");
    vector<P> nodes;
    rep (i, n) nodes.emplace_back(topology[i], n - 1 - i);
    sort(all(nodes));
    for (P p : nodes) eprintf("%d ", p.second); eprintf("\n");
    rep (i, n) {
        if (i == topology.back()) cout << "0\n";
        else {
            int parent = graph_rev[i][0], best = nodes[graph_rev[i][0]].second;
            repp (j, 1, graph_rev[i].size()) {
                if (chmax(best, nodes[graph_rev[i][j]].second)) parent = graph_rev[i][j];
            }
            cout << parent + 1 << "\n";
        }
    }
    return 0;
}