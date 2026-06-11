#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;

struct UnionFind{
    vector<ll> link;
    UnionFind(ll n):link(n,-1){}
    ll find(ll v){
        if(link[v]<0) return v;
        else return link[v]=find(link[v]);
    }
    bool unite(ll v,ll w){
        v=find(v),w=find(w);
        if(v==w) return 0;
        if(link[v]>link[w]) swap(v,w);
        link[v]+=link[w];
        link[w]=v;
        return 1;
    }
    bool same(ll v,ll w){
        return find(v)==find(w);
    }
};

int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll> a(m),b(m),ans(m);
    rep(i,m){
        cin>>a[i]>>b[i];
        a[i]--,b[i]--;
    }
    UnionFind uf(n);
    ans[m-1]=n*(n-1)/2;
    for(ll i=m-1;i>=1;i--){
        if(uf.same(a[i],b[i])) ans[i-1]=ans[i];
        else ans[i-1]=ans[i]-uf.link[uf.find(a[i])]*uf.link[uf.find(b[i])];
        uf.unite(a[i],b[i]);
    }
    rep(i,m) cout<<ans[i]<<endl;
    return 0;
}