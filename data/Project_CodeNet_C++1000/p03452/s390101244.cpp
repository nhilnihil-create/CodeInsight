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
// template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

vector<vector<P>> graph;
vector<ll> dist;
vector<bool> used;
void dfs (int i) {
    for (auto p : graph[i]) {
        if (used[p.second]) continue;
        used[p.second] = true;
        dist[p.second] = p.first + dist[i];
        dfs(p.second);
    }
}
int main (void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    graph.resize(n);
    dist.resize(n);
    rep (i, m) {
        int l, r, d; cin >> l >> r >> d; l--; r--;
        graph[l].emplace_back(d, r);
        graph[r].emplace_back(-d, l);
    }
    used.resize(n);
    rep (i, n) {
        if (!used[i]) {
            used[i] = true;
            dfs(i);
        }
    }
    rep (i, n) {
        for (auto p : graph[i]) {
            if (dist[p.second] - dist[i] != p.first) {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
    return 0;
}