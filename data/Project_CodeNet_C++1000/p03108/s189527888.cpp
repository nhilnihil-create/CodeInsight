#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
ll a[111111];
ll b[111111];
ll res[111111];

struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};

int main(){
    cin >> n >> m;
    for(ll i=0;i<m;i++){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }
    UnionFind tree(n);
    res[m]=n*(n-1)/2;
    for(ll i=m-1;i>=0;i--){
        if(tree.issame(a[i],b[i])){
            res[i]=res[i+1];
        }
        else{
            res[i]=res[i+1]-(tree.size(a[i])*tree.size(b[i]));
        }
        tree.merge(a[i],b[i]);
    }
    for(ll i=1;i<=m;i++){
        cout << res[i] << endl;
    }
    return 0;
}  
