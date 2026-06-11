#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

class UnionFind{
    vector<int>p,sz;
public:
    UnionFind(int n){
        p.resize(n,-1);
        sz.resize(n,1);
    }
    int find(int x){
        if(p[x] == -1)return x;
        else return p[x] = find(p[x]);
    }
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y)return;
        if(sz[x] > sz[y])swap(x,y);
        p[x] = y;
        sz[y] += sz[x];
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
    int size(int x){
        return sz[find(x)];
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    UnionFind uf(n);
    rep(i,m){
        int a,b,c;
        cin>>a>>b>>c;
        a--; b--;
        uf.unite(a,b);
    }
    set<int>ans;
    rep(i,n){
        ans.insert(uf.find(i));
    }
    cout<<ans.size()<<endl;
}