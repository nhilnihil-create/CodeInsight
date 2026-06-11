#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

struct UnionFind {
    vector<int> par;
    UnionFind(int N) : par(N) {
        for (int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
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

    UnionFind tree(N + 1);
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        tree.unite(p[x - 1], p[y - 1]);
    }

    int output = 0;
    for (int i = 0; i < N; i++) {
        if (tree.same(p[i], i + 1)) {
            output++;
        }
    }

    cout << output << endl;

    return 0;
}
