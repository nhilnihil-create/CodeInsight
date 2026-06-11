#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=998244353;

int main(void){
    int n;
    cin>>n;
    Graph G(n);
    map<pair<int,int>,int> weight;
    rep(i,n-1){
        int u,v,w;
        cin>>u>>v>>w;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
        weight[make_pair(u,v)]=w;
        weight[make_pair(v,u)]=w;
    }
    vector<int> dist(n,-1);
    queue<int> que;
    dist[0]=0;
    que.push(0);
    while(!que.empty()){
        int v=que.front();
        que.pop();
        for(int nv:G[v]){
            if(dist[nv]!=-1) continue;
            //cout<<v<<" "<<nv<<" "<<weight[make_pair(v,nv)]<<endl;
            if(weight[make_pair(v,nv)]%2==0) dist[nv]=dist[v];
            else dist[nv]=(dist[v]+1)%2;
            que.push(nv);
        }
    }
    rep(i,n) cout<<dist[i]<<endl;
    return 0;
}