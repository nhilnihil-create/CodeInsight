//Decayed Bridges

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using P = pair<ll,ll>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

struct UnionFind {
    //自身が親であれば、その集合に属する頂点数に-1を掛けたもの
    //そうでなければ親のid
    vector<int>par;
    UnionFind(int n){par=vector<int>(n,-1);}
    int root(int x){
        if(par[x]<0)return x;
        return par[x]=root(par[x]);
    }
    bool unite(int x,int y){
        x=root(x);
        y=root(y);
        if(x==y)return false;
        if(par[x]>par[y])swap(x, y);
        par[x]+=par[y];
        par[y]=x;
        return true;
    }
    bool same(int x,int y){return root(x)==root(y);}
    int size(int x){return -par[root(x)];}
};

signed main (){
    int n,m;cin>>n>>m;
    vector<P>in(m);
    vector<int>out;
    rep(i,0,m)cin>>in[i].first>>in[i].second;
    reverse(range(in));
    UnionFind uf(n);
    int f=n*(n-1)/2;
    rep(i,0,m){
        out.pb(f);
        int a=in[i].first-1,b=in[i].second-1;
        int o=uf.size(a)*uf.size(b);
        if(!uf.unite(a,b))continue;
        f-=o;
        if(f<0)f=0;
        uf.unite(a,b);
    }
    reverse(range(out));
    for(auto i:out)cout<<i<<nnn;
    return 0;
}