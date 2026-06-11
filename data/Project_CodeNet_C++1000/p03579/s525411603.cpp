#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct BipartiteGraph{
    int n,num;
    vector<int> par,rank;
    BipartiteGraph(int n):n(n),num(2*n),par(2*n),rank(2*n,1){
        iota(par.begin(),par.end(),0);
    }
    int root(int x){
        if (par[x]==x) return x;
        return par[x]=root(par[x]);
    }
    bool merge(int x, int y){
        x=root(x),y=root(y);
        if (x==y) return false;
        if (rank[x]<rank[y]) swap(x,y);
        par[y]=x;
        rank[x]+=rank[y];
        --num;
        return true;
    }
    bool same(int x, int y){
        return root(x)==root(y);
    }
    int size(int x){
        return rank[root(x)];
    }
    int count(){
        return num;
    }
    void add_edge(int u,int v){
        merge(u,v+n),merge(u+n,v);
    }
    bool build(){
        for (int i=0;i<n;++i){
            if (same(i,i+n)) return false;
        }
        return true;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M; cin >> N >> M;
    BipartiteGraph BG(N);
    vector<int> deg(N,0);
    for (int i=0;i<M;++i){
        int u,v; cin >> u >> v;
        BG.add_edge(--u,--v);
        ++deg[u]; ++deg[v];
    }
    if (!BG.build()){
        cout << N*(N-1)/2-M << '\n';
        return 0;
    }
    ll cnt=0,ans=0;
    for (int i=0;i<N;++i) cnt+=BG.same(0,i);
    for (int i=0;i<N;++i) if (BG.same(0,i)){
        ans+=N-cnt-deg[i];
    }
    cout << ans << '\n';
}