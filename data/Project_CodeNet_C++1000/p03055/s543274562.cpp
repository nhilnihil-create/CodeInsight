#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("i.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    vector<int> adj[n];
    for(int i = 0;i < n-1;i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int vis[n];
    queue<int> bfs;
    fill(vis,vis+n,-1);
    vis[0] = 0;
    bfs.push(0);
    while(!bfs.empty()){
        int u = bfs.front();

        bfs.pop();
        for(int j = 0;j < adj[u].size();j++){
            int v = adj[u][j];
            if(vis[v] == -1){
                vis[v] = vis[u] + 1;
                bfs.push(v);
            }
        }
    }
    //return 0;
    int maxV = 0;
    int nxtU = 0;
    for(int i = 0;i < n;i++){
        if(maxV < vis[i]){
            nxtU = i;
            maxV = vis[i];
        }
    }



    fill(vis,vis+n,-1);
    vis[nxtU] = 0;
    bfs.push(nxtU);
    while(!bfs.empty()){
        int u = bfs.front();
        bfs.pop();
        for(int j = 0;j < adj[u].size();j++){
            int v = adj[u][j];
            if(vis[v] == -1){
                vis[v] = vis[u] + 1;
                bfs.push(v);
            }
        }
    }

    maxV = 0;
    nxtU = 0;
    for(int i = 0;i < n;i++){
        if(maxV < vis[i]){
            maxV = vis[i];
        }
    }

    if(maxV % 3 == 1) cout << "Second\n";
    else cout << "First\n";


    return 0;
}
