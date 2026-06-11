#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
int INF = 1e9;

struct UnionFind{
    vector<int> d;
    UnionFind(int n):d(n,-1){}
    int find(int x){
        if(d[x]<0) return x;
        return d[x] = find(d[x]);
    }
    bool unite(int x,int  y){
        x = find(x);y = find(y);
        if(x==y) return false;
        if(d[x] > d[y]) swap(x,y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x,int y) {return find(x) == find(y);}
    int size(int x) {return -d[find(x)];}
};

int main(){
    int n,m;cin >> n >> m;
    vector<P> edge(m);
    rep(i,m){
        int a,b;cin >> a >> b;
        --a;--b;
        edge[i] = make_pair(a,b);
    }
    vector<ll> ans(m,0);
    UnionFind tree(100005);
    for(int i = m-1;i >= 0;i--){
        P p = edge[i];
        if(tree.same(p.first,p.second)) ans[i] = 0;
        else{
            ans[i] = ll(tree.size(p.first))*ll(tree.size(p.second));
            tree.unite(p.second,p.first);
        }
    }
    rep(i,m-1) ans[i+1] += ans[i];
    rep(i,m) cout << ans[i] <<endl;; 
    
}