#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int n,m;
vector<vector<int>>adj;
vector<int>in_dig,s_path;
queue<int>Q;

void bfs(){
    while(!Q.empty()){
        auto node=Q.front();Q.pop();
        for(auto child:adj[node]){
            s_path[child]=max(s_path[child], s_path[node]+1);
            in_dig[child]--;
            if(!in_dig[child]){
                Q.push(child);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin>>n>>m;
    adj.resize(n+1);
    in_dig.resize(n+1);
    s_path.resize(n+1);
    // vis.resize(n+1);
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        in_dig[b]++;
    }

    for(int node=1; node<=n; node++){
        if(in_dig[node]==0)Q.push(node);
    }

    bfs();

    int ans=0;
    for(int node=1; node<=n; node++)ans=max(ans,s_path[node]);
    cout<<ans<<endl;

    return 0;
}