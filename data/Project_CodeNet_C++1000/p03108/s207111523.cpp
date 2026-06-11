#include <bits/stdc++.h>
using namespace std;

//頂点は0からN-1
struct UnionFind {
    //par[i]はiの親
    //親のときは木のサイズの-1倍
    vector<int> par;

    //すべてが根として初期化
    //ここの書き方がわからない
    UnionFind(int N) : par(N) {
        for(int i = 0; i < N; i++) par[i] = -1;
    }
    
    // 木の根
    int root(int x) {
        if (par[x] < 0) return x;
        return par[x] = root(par[x]);
    }

    // 木の併合
    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        par[ry] += par[rx];
        par[rx] = ry;
    }
    
    // x, yが属する木が同じか判定
    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {
    long long V,E;
    cin >> V >> E;
    UnionFind tree(V);
    int x[100005], y[100005];
    for(int i=0; i<E; i++){
        int p,q;
        cin >> p >> q;
        x[E-i-1] = p-1;
        y[E-i-1] = q-1;
    }
    long long s[100005];
    s[0]=V*(V-1)/2;
    for(int i=0; i<E; i++){
        int rx = tree.root(x[i]);
        int ry = tree.root(y[i]);
        if(rx == ry){
            s[i+1] = s[i];
        } else{
            long long sx =  tree.par[rx];
            long long sy =  tree.par[ry];
            s[i+1] = s[i] - sx*sy;
            tree.unite(rx,ry);
        }        
    }
    for(int i=0; i<E; i++) cout << s[E-1-i] << endl;
}