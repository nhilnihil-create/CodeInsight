#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353,INF=1e18;

int N;
vector<vector<P>> g;
vector<int> ans;
void dfs(int p,int v){
    for(P x:g[v]){
        int u=x.first,w=x.second;
        if(u==p)continue;
        if(w%2==0){ans[u]=ans[v];}
        else{ans[u]=ans[v]*(-1);}
        dfs(v,u);
    }
    return;
}

int main() {
    cin>>N;
    g.resize(N);
    ans.resize(N);
    rep(i,N-1){
        int u,v,w;
        cin>>u>>v>>w;
        --u;--v;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    ans[0]=1;
    dfs(-1,0);
    rep(i,N){
        if(ans[i]==-1){
            ans[i]=0;
        }
        cout<<ans[i]<<endl;
    }
}