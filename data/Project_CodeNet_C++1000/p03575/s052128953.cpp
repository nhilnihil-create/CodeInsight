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
    vector<int> a(m),b(m);
    rep(i,m){
        cin>>a[i]>>b[i];
        a[i]--;
        b[i]--;
    }

    int ans=0;
    rep(i,m){
        UnionFind uf(n);
        rep(j,m){
            if(i==j) continue;
            uf.merge(a[j],b[j]);
        }
        rep(i,n){
            if(uf.size(i)!=n){
                ans++;
                break;
            }
        }
    }

    cout<<ans<<endl;
} 
