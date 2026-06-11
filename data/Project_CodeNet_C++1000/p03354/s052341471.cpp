#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define itn int
#define P pair<int,int>
#define rep2(i,a,n) for(int i = (a);i < (n);i++)
#define rep(i,n) rep2(i,0,n)

struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n){
        for(int i = 0;i < n;i++)par[i] = i;
    }
    
    int root(int x){
        if(par[x] == x)return x;
        return par[x] = root(par[x]);
    }
    
    void unite(int x,int y){
        if(root(x) == root(y))return;
        par[root(x)] = root(y);
    }
    
    bool same(int x,int y){
        return root(x) == root(y);
    }
};

int main(void){
    int n,m;
    cin >> n >> m;
    
    UnionFind tree(n);
    
    int p[n],x[m],y[m];
    for(int i = 0;i < n;i++){
        cin >> p[i];
        p[i]--;
    }
    for(int i = 0;i < m;i++){
        cin >> x[i] >> y[i];
        x[i]--;y[i]--;
        tree.unite(x[i],y[i]);
    }
    
    int alina = 0;
    for(int i = 0;i < n;i++){
        if(tree.same(i,p[i])){
            tree.unite(i,p[i]);
            alina++;
        }
    }
    cout << alina << endl;
}