#include <bits/stdc++.h>
#include <cmath>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<pair<int,int>> vp;
const ll INF = 1e18;
#define foreach(ix,a) for(auto& (ix) : (a) 
struct UnionFind {
    vector<int> par;
 
    UnionFind(int N) : par(N,-1) {}
 
    int root(int x) { 
        if (par[x] < 0) return x;
        return par[x] = root(par[x]);
    }
    void unite(int x, int y) { 
        int rx = root(x); 
        int ry = root(y);
        if (rx == ry) return; 
        if(size(x)<size(y))swap(rx,ry);
        par[rx]+=par[ry];
        par[ry]=rx;
    }
    bool same(int x, int y) { 
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
    int size(int x){
        return -par[root(x)];
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    UnionFind f(n);
    rep(i,m){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        f.unite(a,b);
    }
    set<int>res;
    rep(i,n){
        res.insert(f.root(i));
    }
    cout<<res.size()<<endl;
}