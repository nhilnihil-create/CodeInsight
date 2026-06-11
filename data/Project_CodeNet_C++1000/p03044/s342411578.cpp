#include<iostream>
#include<vector>
using namespace std;
using Edge=pair<int,int>;
using Graph=vector<vector<Edge>>;

int n;
Graph G;
vector<int> ans;

void dfs(int v, int p, int c){
    ans[v]=c;
    for(auto e : G[v]){
        if(e.first==p) continue;
        if(e.second%2==1) dfs(e.first,v,1-c);
        else dfs(e.first,v,c);
    }
}

int main(){
    cin>>n;
    G.resize(n);
    for(int i=0;i<n-1;++i){
        int u,v,w;
        cin>>u>>v>>w;
        --u; --v;
        G[u].push_back(Edge(v,w));
        G[v].push_back(Edge(u,w));
    }

    ans.assign(n,-1);
    dfs(0,-1,0);

    for(int i=0;i<n;++i) cout<<ans[i]<<endl;
}