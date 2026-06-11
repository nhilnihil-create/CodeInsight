#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,N-1,0)
#define RREPS(i,n) RFOR(i,N,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
const int INF=1e18;
const int MOD=1e9+7;
struct UnionFind {
    public:
    vector<int> par;
    UnionFind(int n){
        par=vector<int>(n,-1);
    }
    int root(int x){
        if(par[x]<0)return x;
    return par[x]=root(par[x]);
    }
    bool issame(int x,int y){
        return root(x)==root(y);
    }
    bool merge(int x,int y){
        x=root(x);
        y=root(y);
        if(x==y)return false;
        if(par[x]>par[y])swap(x,y);
        par[x]+=par[y];
        par[y]=x;
        return true;
    }
    int size(int x){
        return -par[root(x)];
    }
};

signed main(){
    int N,M;cin>>N>>M;
    vector<pair<int,int>> p(M);
    REP(i,M){
        int a,b;cin>>a>>b;a--;b--;
        p[i]={a,b};
    }
    reverse(all(p));
    UnionFind uf(N);
    vector<int> ans(M);
    REP(i,M)ans[i]=N*(N-1)/2;
    REP(i,M-1){
        if(uf.issame(p[i].first,p[i].second))ans[i+1]=ans[i];
        else{
            int x=uf.size(p[i].first);
            int y=uf.size(p[i].second);
            ans[i+1]=ans[i]-x*y;
            uf.merge(p[i].first,p[i].second);
        }
    }
    reverse(all(ans));
    REP(i,M)cout<<ans[i]<<endl;
}