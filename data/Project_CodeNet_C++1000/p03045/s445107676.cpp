#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define int long long
using P = pair<int,int>;
struct UnionFind {
vector<int> d;
UnionFind(int n):d(n,-1){}
int root(int x){
    if(d[x] <0) return x;
    return d[x] = root(d[x]);
}
bool unite(int x,int y){
    x = root(x),y = root(y);
    if(x == y) return false;
    if(d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
}
int size(int x) {return -d[root(x)];}
bool same(int x,int y){return root(x) == root(y);}
};
int seen[110000];
signed main(){
    int n,m;cin >>n >> m;
    UnionFind uf(n);
    rep(i,m){
        int x,y,z;cin >> x >> y >> z;
        x--;y--;
        uf.unite(x,y);

    }
    int ans = 0;
    rep(i,n){
        auto hoge = uf.root(i);
        if(seen[hoge] == 0)ans++;
        seen[hoge] = 1;
    }
    cout << ans << endl;
    


    return 0;
}