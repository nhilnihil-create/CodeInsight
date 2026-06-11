#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

struct UnionFind{
    vector<int> par;

    UnionFind(int n) : par(n,-1) { }
    void init(int n) { par.assign(n,-1); }

    int root(int x){
        if(par[x]<0) return x;
        else return par[x]=root(par[x]);
    }

    bool issame(int x,int y){
        return root(x)==root(y);
    }

    bool merge(int x,int y){
        x=root(x);
        y=root(y);
        if(x==y) return false;
        if(par[x]>par[y]) swap(x,y);
        par[x]+=par[y];
        par[y]=x;
        return true;
    }

    int size(int x){
        return -par[root(x)];
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    int a[m],b[m];
    rep(i,m){
        cin>>a[i]>>b[i];
        a[i]--,b[i]--;
    }

    vector<ll> ans;
    UnionFind uf(n);
    for(int i=m-1;i>=0;i--){
        if(uf.issame(a[i],b[i])) ans.push_back(0);
        else{
            ll x=uf.size(a[i]);
            ll y=uf.size(b[i]);
            ll tmp=x*y;
            ans.push_back(tmp);
        }
        uf.merge(a[i],b[i]);
    }

    reverse(all(ans));
    for(int i=1;i<m;i++) ans[i]+=ans[i-1];

    rep(i,m) cout<<ans[i]<<endl;
    
}
