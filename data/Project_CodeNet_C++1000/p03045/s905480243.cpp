#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int> >g(n + 3);
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int k = 0;
    vector<int>vis(n + 3, 0);
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            k++;
            vis[i] = 1;
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int j = 0; j < g[u].size(); j++){
                    int v = g[u][j];
                    if(vis[v] == 0){
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }
        }
    }
    cout << k;
    return 0;
}