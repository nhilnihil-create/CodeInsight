#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
using LP=pair<ll,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;

struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    
    int root(int x) {//xの親を求める
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {//xとyが連結しているか判定
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {//xとyを連結
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {//xを含む木のサイズを求める
        return -par[root(x)];
    }
};

int main() {
    ll N,M;
    cin>>N>>M;
    vector<P> bridge(0);
    rep(i,M){
        int a,b;
        cin>>a>>b;
        --a;--b;
        bridge.pb({a,b});
    }
    vector<ll> ans(M);
    ans.at(M-1)=N*(N-1)/2;
    UnionFind uf(N);
    for(int i=M-1;i>=1;i--){
        int a=bridge.at(i).first,b=bridge.at(i).second;
        if(uf.issame(a,b)){
            ans.at(i-1)=ans.at(i);
        }
        else{
            ll sa=uf.size(a),sb=uf.size(b);
            ans.at(i-1)=ans.at(i)-sa*sb;
            uf.merge(a,b);
        }
    }
    rep(i,M){
        cout<<ans.at(i)<<endl;
    }
}