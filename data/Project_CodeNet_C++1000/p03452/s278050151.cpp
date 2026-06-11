#include <bits/stdc++.h>
using namespace std;

struct UnionFind{
    vector<int> par;
    vector<int> sz;
    UnionFind(int n){
        par.resize(n);
        sz.resize(n, 1);
        for(int i = 0; i < n; i++) par[i] = i;
    }
    int root(int x){
        if(x == par[x]) return x;
        return par[x] = root(par[x]);
    }
    bool unite(int x, int y){
        x = root(x); y = root(y);
        if(x == y) return false;
        if(sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
        return true;
    }
    bool same(int x, int y){
        return root(x) == root(y);
    }
};

struct WeightedUnionFind{
    vector<int> par;
    vector<int> sz;
    vector<int> diff_weight;
    WeightedUnionFind(int n){
        par.resize(n);
        sz.resize(n, 1);
        diff_weight.resize(n);
        for(int i = 0; i < n; i++) par[i] = i;
    }
    int root(int x){
        if(x == par[x]) return x;
        int r = root(par[x]);
        diff_weight[x] += diff_weight[par[x]];
        return par[x] = r;
    }
    int weight(int x){
        root(x);
        return diff_weight[x];
    }
    int diff(int x, int y){
        return weight(y) - weight(x);
    }
    // weight(y) - weight(x) = w となるように merge する
    bool unite(int x, int y, int w){
        // x と y それぞれについて、 root との重み差分を補正
        w += weight(x) - weight(y);
        x = root(x); y = root(y);
        if(x == y) return false;
        if(sz[x] < sz[y]) swap(x, y), w = -w;
        sz[x] += sz[y];
        par[y] = x;
        // x が y の親になるので、x と y の差分を diff_weight[y] に記録
        diff_weight[y] = w;
        return true;
    }
    bool same(int x, int y){
        return root(x) == root(y);
    }
};

/*
verified
https://beta.atcoder.jp/contests/arc090/tasks/arc090_b
*/

int main(){
    int n, m;
    cin >> n >> m;
    WeightedUnionFind uf(n);
    bool f = true;
    for(int i = 0; i < m; i++){
        int l, r, d;
        cin >> l >> r >> d;
        l--; r--;
        if(!uf.same(l, r)){
            uf.unite(l, r, d);
        }else{
            if(uf.diff(l, r) != d) f = false;
        }
    }
    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;
}