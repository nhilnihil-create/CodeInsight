#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
using LP=pair<ll,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;

vector<int> checked;
vector<vector<int>> to;
vector<ll> black,white;

void dfs(int v,int p=-1){
    if(checked[v])return;
    checked[v]=1;
    if(to[v].size()==1 && to[v][0]==p){
        black.at(v)=1;
        white.at(v)=1;
        return;
    }
    ll bl=1,wh=1;
    for(int u:to[v]){
        if(u==p)continue;
        dfs(u,v);
        bl*=white[u];
        wh*=(black[u]+white[u])%MOD;
        bl%=MOD;wh%=MOD;
    }
    black.at(v)=bl;
    white.at(v)=wh;
    return;
}

int main() {
    int N;
    cin>>N;
    checked.resize(N);
    to.resize(N,vector<int>(0));
    black.resize(N);
    white.resize(N);
    rep(i,N-1){
        int x,y;
        cin>>x>>y;
        --x;--y;
        to[x].pb(y);
        to[y].pb(x);
    }
    dfs(0);
    ll ans=black[0]+white[0];
    ans%=MOD;
    cout<<ans<<endl;
}