#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
struct unionfind{
    public:
    vector<ll>par;
    vector<ll>siz;
    unionfind(ll n) :par(n),siz(n,1LL){
        rep(0,i,n)par[i]=i;
    }
    ll root(ll x){
        if(par[x]==x)return x;
        return par[x]=root(par[x]);
    }
    bool merge(ll x,ll y){
        x=root(x);
        y=root(y);
        if(x==y)return false;
        if(siz[x]<siz[y])swap(x,y);
        siz[x]+=siz[y];
        par[y]=x;
        return true;
    }
    bool same(ll x,ll y){
        ll rx=root(x);
        ll ry=root(y);
        return rx==ry;
    }
    ll size(ll x){
        return siz[root(x)];
    }
};
int main(void){
    // Your code here!
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>a(m);
    rep(0,i,m){
        cin>>a[i].first>>a[i].second;
        --a[i].first,--a[i].second;
    }
    ll ans[m+1];
    unionfind tree(n);
    ans[m]=n*(n-1)/2;
    rep(0,i,m){
        ll na=a[m-1-i].first,nb=a[m-1-i].second;
        ll sa=tree.size(na),sb=tree.size(nb);
        if(tree.merge(na,nb))ans[m-1-i]=ans[m-i]-sa*sb;
        else ans[m-1-i]=ans[m-i];
    }
    rep(1,i,m+1)cout<<ans[i]<<endl;
}