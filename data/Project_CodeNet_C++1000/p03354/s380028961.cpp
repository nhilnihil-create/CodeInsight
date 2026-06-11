#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
#define MOD 1000000007

struct UnionFind {
    vector<int> par;

    UnionFind(int N) : par(N) { rep(i, N) par[i] = i; }

    int root(int x) {
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }

    void merge(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry)
            return;
        par[rx] = ry;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> P(N);
    rep(i, N) { cin >> P[i]; }

    UnionFind tree(N);

    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tree.merge(a, b);
    }

    int cnt = 0;
    rep(i, N) {
        if (tree.same(i, P[i] - 1))
            cnt++;
    }

    cout << cnt << endl;
}