#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pint;

const int INF=1e9;
vector<vector<int>> G,G1;
vector<int> par;

void dfs(int v)
{
    for(int u:G1[v]){
        par[u]=v;
        dfs(u);
    }
}

signed main()
{
    int N,M; cin>>N>>M;
    G.resize(N);
    M+=N-1;
    vector<int> indeg(N);
    for(int i=0;i<M;i++){
        int a,b; cin>>a>>b;
        a--; b--;
        G[a].push_back(b);
        indeg[b]++;
    }
/*
    for(int i=0;i<N;i++) cout<<indeg[i]<<' ';
    cout<<endl;
*/
    stack<int> S;
    vector<int> dp(N,-INF);
    for(int i=0;i<N;i++){
        if(indeg[i]==0){
            S.push(i);
            dp[i]=0;
        }
    }
    while(!S.empty()){
        int v=S.top();
        S.pop();
        for(int u:G[v]){
            dp[u]=max(dp[u],dp[v]+1);
            indeg[u]--;
            if(indeg[u]==0){
                S.push(u);
            }
        }
    }
/*
    for(int i=0;i<N;i++) cout<<dp[i]<<' ';
    cout<<endl;
*/
    G1.resize(N);
    for(int v=0;v<N;v++){
        for(int u:G[v]){
            if(dp[u]==dp[v]+1){
                G1[v].push_back(u);
            }
        }
    }
    par.resize(N);
    for(int i=0;i<N;i++){
        par[i]=-1;
    }
    for(int i=0;i<N;i++){
        if(par[i]==-1){
            dfs(i);
        }
    }
    for(int i=0;i<N;i++){
        cout<<par[i]+1<<endl;
    }
}
