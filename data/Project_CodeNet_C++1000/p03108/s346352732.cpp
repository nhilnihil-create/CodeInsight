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
    vector<int>a(m),b(m);
    rep(i,m){
        cin>>a[i]>>b[i];
        a[i]--; b[i]--;
    }
    vector<ll>ans;
    ll now=(ll)n*(n-1)/2;
    ans.push_back(now);
    for(int i=m-1; i>=0; --i){
        if(!uf.same(a[i],b[i])){
            ans.push_back(now-(ll)uf.size(a[i])*uf.size(b[i]));
            now-=(ll)uf.size(a[i])*uf.size(b[i]);
        }
        else{
            ans.push_back(now);
        }
        uf.unite(a[i],b[i]);
    }
    reverse(ans.begin(),ans.end());
    for(int i=1; i<ans.size(); ++i)cout<<ans[i]<<endl;
}