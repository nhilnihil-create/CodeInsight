#include <bits/stdc++.h>
#define REP(i, a) for(int i=0; i<int(a); i++)
#define ALL(x) begin(x), end(x)
#define VI vector<int>
using namespace std;
typedef long long LL;

const int MAX_N=100005;

struct WeightedUnionFind {
    int n;
    int INF = 1e9;
    vector<int> par, sz, weight;

    WeightedUnionFind() {}
    WeightedUnionFind(int n_) : n(n_), par(n_, 0), sz(n_, 1), weight(n_, 0) { iota(begin(par), end(par), 0); }

    int find(int x) { 
        if(x==par[x]) return x;
        int y = find(par[x]);
        weight[x]+=weight[par[x]];
        return par[x]=y;
    }

    void unite(int x, int y, int w) {
        int px = find(x);
        int py = find(y);
        if(px == py) return;
        if(sz[px] < sz[py]) {
            swap(px, py);
            swap(x, y);
            w = -w;
        }
        sz[px] += sz[py];
        par[py] = px;
        weight[py] = weight[x] - w - weight[y];            
    }

    int same(int x, int y) { return find(x) == find(y); }

    int diff(int x, int y) { // x -> y
        if(same(x, y)) return weight[x]-weight[y];
        return INF;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    WeightedUnionFind wuf(n+1);

    while(m--) {
        int a, b, w;
        cin >> a >> b >> w;
        if(wuf.same(a,b)) {
            if(wuf.diff(a,b) != w) {
                cout << "No" << endl;
                return 0;
            }
        } else {
            wuf.unite(a,b,w);
        }
    }
    cout << "Yes" << endl;
    return 0; 
}