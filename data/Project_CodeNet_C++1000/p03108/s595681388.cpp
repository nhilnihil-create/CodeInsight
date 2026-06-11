#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for(int i=m; i<n; i++)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
template <typename T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;} return 0; }
template <typename T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1;} return 0; }
const int INF = 1000000000;

struct UnionFind
{
    vi par;
    vi sizes;
    UnionFind(int n) : par(n), sizes(n,1){
        rep(i,0,n) par[i] = i;
    }
    int find(int x){
        if(par[x]==x) return x;
        return par[x] = find(par[x]);
    }
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y) return;
        if(sizes[x]<sizes[y]) swap(x,y);
        par[y] = x;
        sizes[x] += sizes[y];
    }
    bool same(int x, int y){
        return find(x)==find(y);
    }
    int size(int x){
        return sizes[find(x)];
    }
};

int main(){
    ll N,M; cin>>N>>M;
    UnionFind uf(N);
    ll a[M],b[M];
    rep(i,0,M){
        cin>>a[i]>>b[i];
        a[i]--,b[i]--;
    } 
    ll ans[M+1];
    ll rec=N*(N-1)/2;
    ans[M] = rec;
    for(int i=M-1;i>=0;i--){
        if(uf.same(a[i],b[i])) ans[i]=rec;
        else{
            rec-=uf.size(a[i])*uf.size(b[i]);
            ans[i]=rec;
            uf.unite(a[i],b[i]);
        }
    }
    rep(i,1,M+1) cout<<ans[i]<<endl;

}