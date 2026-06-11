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
    ll n,m,x,y,z;
    cin>>n>>m;
    UnionFind uf(n);
    rep(i,m){
        cin>>x>>y>>z;
        x--,y--;
        uf.unite(x,y);        
    }
    map<ll,ll> mp;
    rep(i,n) mp[uf.find(i)];
    cout<<mp.size()<<endl;
    return 0;
}