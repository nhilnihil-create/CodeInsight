#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct unionfind{
    vector<ll> root,siz;

    void init(ll n){
        for(int i=0;i<n;i++){
            root.push_back(i);
        }
        siz.assign(n,1);
    }

    ll find(ll x){
        if(root[x]==x){
            return x;
        }
        return find(root[x]);
    }

    void unite(ll x,ll y){
            x=find(x);
            y=find(y);
            if(x==y){
                return;
            }
            if(siz[x]<siz[y]){
                swap(x,y);
            }
            siz[x]+=siz[y];
            root[y]=x;
            return;
    }

    bool check(ll x,ll y){
        return find(x)==find(y);
    }

    ll size(ll x){
        return siz[find(x)];
    }

};

int main(){

    ll n,m;
    cin>>n>>m;
    unionfind uf;
    uf.init(n);
    vector<pair<ll,ll>> edge(m);
    for(ll i=0;i<m;i++){
        cin>>edge[i].first>>edge[i].second;
        edge[i].first--;
        edge[i].second--;
    }
    vector<ll> ans(m);
    ans[m-1]=(n*(n-1))/2;
    for(ll i=m-2;i>-1;i--){
        ll a=edge[i+1].first;
        ll b=edge[i+1].second;
        if(uf.check(a,b)){
            ans[i]=ans[i+1];
            continue;
        }
        ans[i]=max(0ll,ans[i+1]-(uf.size(a)*uf.size(b)));
        uf.unite(a,b);
    }
    for(ll i=0;i<m;i++){
        cout<<ans[i]<<endl;
    }


return 0;
}
