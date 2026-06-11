#include <bits/stdc++.h>
using namespace std;

struct Fast {Fast() {std::cin.tie(0); ios::sync_with_stdio(false);}} fast;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vll = vector<long long>;
using pll = pair<ll, ll>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007

struct UnionFind {
    vector<int> par, rank;

    UnionFind(int n) : par(n , -1), rank(n, 0) { }
    void init(int n) { par.assign(n, -1), rank.assign(n, 0); }

    int root(int x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]); //ここで経路圧縮
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        return true;
    }
};

int main() {
    ll N, M; cin >> N >> M ;
    UnionFind tree(2 * N);
    rep(i, M) {
        int a, b; cin >> a >> b;
        a--; b--;
        tree.unite(a, b + N);
        tree.unite(a + N, b);
    }
    bool g = true;
    rep(i, N) {
        if (tree.same(i, i + N)) {
            g = false;
            break;
        }
    }
    if (!g) {
        cout << N*(N - 1) / 2 - M << endl;
    }
    else {
        ll l = 0;
        rep(i, N) {
            if (tree.same(0, i)) l++;
        }
        cout << l*(N - l) - M << endl;
    }

}
