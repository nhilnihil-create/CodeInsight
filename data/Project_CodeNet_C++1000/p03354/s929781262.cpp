#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <iterator>
#include <set>
#include <queue>
#include <bitset>
#include <cassert>

using namespace std;

struct UnionFind {

    // par[i] is parent of i
    // root of i is par[par[par[../par[i]...]]]
    vector<int> par;
    vector<int> sz;

    UnionFind(int N) : par(N), sz(N) {
        for (int i = 0; i < N; ++i) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            // path compression
            return par[x] = find(par[x]);
        }
    }

    bool same(int p, int q) {
        return find(p) == find(q);
    }

    void unite(int p, int q) {

        int pr = find(p);
        int qr = find(q);
        if (pr == qr) {
            return;
        }
        if (sz[pr] < sz[qr]) {
            par[pr] = qr;
            sz[qr] += sz[pr];
        } else {
            par[qr] = pr;
            sz[pr] += sz[qr];
        }
    }

    int size(int x) {
        return sz[par[x]];
    }

    string asString() {
        string sb;
        for (int i = 0; i < par.size() - 1; ++i) {
            sb += to_string(par[i]);
            sb += ",";
        }
        sb += to_string(par[par.size() - 1]);
        return sb;
    }
};

int main() {
    int N;
    cin >> N;

    int M;
    cin >> M;
    vector<int> ps(N);
    for (int i = 0; i < N; ++i) {
        int p;
        cin >> p;
        ps[i] = p;
    }

    UnionFind unionFind(N);

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        unionFind.unite(x-1, y-1);
    }
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        if (unionFind.same(ps[i]-1, i)) {
            cnt += 1;
        }
    }

    cout << cnt << endl;
}