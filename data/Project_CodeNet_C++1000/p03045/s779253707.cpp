#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

struct UnionFind{
    vector<int> par;
    UnionFind(int n): par(n){
        rep(i,n) par[i]=i;
    }
    //親さがし
    int root(int x){
        if(par[x]==x) return x;
        return par[x]= root(par[x]);//経路短くしとく
    }
    //くっつける
    void unite(int x, int y){
        int rx = root(x); 
        int ry = root(y);
        if(ry==rx) return;
        par[rx]=ry;
    }
    //同じグループかどうか
    bool same(int x, int y){
        if(root(x)==root(y)) return true;
        else return false;
    }


};

int main() {
    int n, m;
    cin >> n >> m;
    UnionFind tree(n);
    rep(i,m) {
        int a, b, z;
        cin >> a >> b >> z;
        --a, --b;
        tree.unite(a, b);
    }
    set<int> s;
    rep(i,n) {
        s.insert(tree.root(i));
    }
    cout << s.size() << endl;
    return 0;
}