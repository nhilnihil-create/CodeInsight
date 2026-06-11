#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G(4);
vector<bool> visited(4);

void dfs(int cur,int pre){
    if(G[cur].size() == 0) return;
    visited[cur] = true;
    for(auto a : G[cur]){
        if(a == pre) continue;
        if(visited[a]) continue;
        else {
            dfs(a,cur);
            break;
        }
    }
}

int main(){
    for(int i=0; i<3; i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    fill(visited.begin(),visited.end(),false);

    dfs(0,-1);

    bool flag = true;

    for(int i=0; i<4; i++){
        if(!visited[i]) flag = false;
    }

    cout<<(flag ? "YES" : "NO")<<endl;

    return 0;
}