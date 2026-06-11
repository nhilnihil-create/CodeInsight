#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
//const int INF = 1<<29;
using namespace std;

struct UnionFind {
    vector<int> par;
    
    UnionFind(int N) : par(N){
        for (int i = 0; i < N; i++) par[i] = i;
    }
    
    int root (int x){
        if (par[x] == x) return x;
        else return par[x] = root(par[x]);
    }
    
    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        par[rx] = ry;
    }
    
    bool same (int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main(){
    int N, M;
    cin >> N >> M;
    
    UnionFind tree(N);
    
    vector<int> p(N);
    rep(i, 0, N) cin >> p.at(i);
    vector<int> x(M), y(M);
    rep(i, 0, M){
        int x, y;
        cin >> x >> y;
        tree.unite(x - 1, y - 1);
    }
    int cnt = 0;
    rep(i, 0, N){
        if (tree.same(i, p.at(i) - 1)) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
