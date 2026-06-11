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
const ll mod =1000000007;
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
    ll n,m;
    cin>>n>>m;
    UnionFind f(n);
    vi a(m),b(m);
    rep(i,m){
        cin>>a[i]>>b[i];
        a[i]--;b[i]--;
    }
    vl ans(m+1,0);
    ans[m]=n*(n-1)/2;
    //f.unite(a[m-1],b[m-1]);
    rep(i,m){
        if(f.same(a[m-i-1],b[m-i-1])){
            ans[m-i-1]=ans[m-i];
        }
        else{
            ans[m-i-1]=ans[m-i]-(f.size(a[m-i-1])*f.size(b[m-i-1]));
            //cout<<(f.size(a[m-i-1])*f.size(b[m-i-1]))<<endl;
        }
        f.unite(a[m-i-1],b[m-i-1]);
    }
    rep(i,m)cout<<ans[i+1]<<endl;
}