#include<bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> par; 
    UnionFind(int N) : par(N) { 
        for(int i = 0; i < N; i++) par[i] = i;
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
    void reset(int n){ 
        for(int i=0;i<n;i++)par[i] = root(par[i]);
    }
    bool con(int x,int y){
        return par[x]==par[y];
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    UnionFind tree(n);
    int p[n];
    for(int i=0;i<n;i++)cin >> p[i];
    int x,y;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        tree.unite(x-1, y-1);
    }
    tree.reset(n);
    int ans=0;
    for(int i=0;i<n;i++)ans += tree.con(i,p[i]-1);
    cout << ans << endl;
}