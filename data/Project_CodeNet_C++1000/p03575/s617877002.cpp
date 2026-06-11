#include <bits/stdc++.h>
using namespace std;

//頂点は0からn-1
struct UnionFind {
    //par[i]はiの親で根のときは自分自身
    vector<int> par;

    //すべてが根として初期化
    //ここの書き方がわからない
    UnionFind(int N) : par(N) {
        for(int i = 0; i < N; i++) par[i] = i;
    }
    
    // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    // 木の併合
    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        par[rx] = ry; //xとyの根が同じでない時：xの根rxをyの根ryにつける
    }
    
    // x, yが属する木が同じか判定
    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {
    int ans=0;

    int V,E;
    cin >> V >> E;
    int x[55], y[55];
    for(int i=0; i<E; i++){
        int p,q;
        cin >> p >> q;
        x[i] = p-1;
        y[i] = q-1;
    }

    for(int k=0; k<E; k++){
        UnionFind tree(V);
        for(int i=0; i<E; i++){
            if(i == k) continue;
            tree.unite(x[i], y[i]);
        }
        bool connected=true;
        for(int i=0; i<V; i++){
            if(!tree.same(0,i)) connected=false;
        }
        if(!connected) ans++;
    }

    cout << ans << endl;
}