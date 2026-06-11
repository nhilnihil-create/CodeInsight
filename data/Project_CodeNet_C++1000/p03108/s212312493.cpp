// https://atcoder.jp/contests/abc120/tasks/abc120_d

#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <regex>
#include <set>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

#define EPS (1e-7)
#define INF (1e9)
#define MOD (1000000007)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOREACH(x, a) for (auto &(x) : (a))
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()

// long gcd(long a, long b) { return b ? gcd(b, a % b) : a; }
// long lcm(long a, long b) { return a * b / gcd(a, b); }
struct UnionFind {
    vector<int> par; // 親の番号
    UnionFind(int size) : par(size, -1) {}
    // xとyの木を併合
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x != y) {
            if (par[y] < par[x])
                swap(x, y);
            par[x] += par[y];
            par[y] = x;
            return true;
        } else {
            return false;
        }
    }
    // 2つのデータx, yが属する木が同じならtrueを返す
    bool same(int x, int y) { return root(x) == root(y); }
    // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    int root(int x) { return par[x] < 0 ? x : par[x] = root(par[x]); }
    // 頂点 v が属するグループと同じグループに属する頂点数を得る
    int size(int x) { return -par[root(x)]; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, t1, t2;
    cin >> n >> m;
    vector<ll> ans, a, b;

    for (int i = 0; i < m; i++) {
        cin >> t1 >> t2;
        a.push_back(--t1);
        b.push_back(--t2);
    }
    reverse(ALL(a));
    reverse(ALL(b));
    UnionFind tree(n);

    ll cur = n * (n - 1) / 2;
    for (int i = 0; i < m; i++) {
        ans.push_back(cur);
        t1 = tree.size(a[i]);
        t2 = tree.size(b[i]);
        if (tree.unite(a[i], b[i])) {
            cur -= t1 * t2;
        }
    }
    reverse(ALL(ans));
    for (auto x : ans) {
        cout << x << '\n';
    }

    return 0;
}
