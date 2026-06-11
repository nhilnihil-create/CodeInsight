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
    vector<ll> p(n),ip(n);
    rep(i,n){
        cin>>p[i];
        p[i]--;
    }
    UnionFind uf(n);
    rep(i,m){
        ll x,y;
        cin>>x>>y;
        x--,y--;
        uf.unite(x,y);
    }
    ll ans=0;
    rep(i,n){
        if(uf.find(i)==uf.find(p[i])) ans++;
    }
    cout<<ans<<endl;
    return 0;
}