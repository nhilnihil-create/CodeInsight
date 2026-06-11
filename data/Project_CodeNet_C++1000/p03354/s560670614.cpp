#include <bits/stdc++.h>
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n,s) for(int i=(s);i<(n);i++)
#define rrep(i,n) for(int i=(n-1);i>=0;i--)
#define rreps(i,n,s) for(int i=s;i>=n;i--)
#define MOD 1000000007
using ll = long long;
using namespace std;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

struct UnionFind{
    vector<ll> par;
    vector<ll> siz;
    UnionFind(ll N): par(N),siz(N,1LL){
        rep(i,N)par[i]=i;
    }
    void init(ll N){
        par.resize(N);
        siz.assign(N,1LL);
        rep(i,N)par[i]=i;
    }

    ll root(ll x){
        if(par[x]==x)return x;
        return par[x]=root(par[x]);
    }

    ll size(ll x){
        return siz[root(x)];
    }
    bool unite(ll x,ll y){
        ll rx = root(x);
        ll ry = root(y);
        if(rx==ry) return false;
        if(siz[rx]<siz[ry])swap(rx,ry);
        siz[rx]+=siz[ry];
        par[ry] = rx;
        return true;
    }
    bool same(ll x,ll y){
        ll rx = root(x);
        ll ry = root(y);
        return rx==ry;
    }
};

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
int n,m;
cin>>n>>m;
vector<int>p(n);
rep(i,n){
    cin>>p[i];
    p[i]--;
}

int x,y;
UnionFind u(n);
rep(i,m){
    cin>>x>>y;x--,y--;
    u.unite(p[x],p[y]);
}
ll ans = 0;
rep(i,n){
    if(p[i]==i||u.same(p[i],i))ans++;
}
cout<<ans<<endl;
//system("pause");
return 0;
}