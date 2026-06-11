#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<pair<int, long long> > >g(n + 3);
    for(int i = 1; i < n; i++){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<int>vis(n + 3, 0), col(n + 3);
    vector<long long>dist(n + 3);
    vis[1] = 1;
    dist[1] = 0;
    col[1] = 0;
    queue<int>q;
    q.push(1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < g[u].size(); i++){
            pair<int, long long>p = g[u][i];
            int v = p.first;
            if(vis[v] == 0){
                vis[v] = 1;
                dist[v] = dist[u] + p.second;
                col[v] = dist[v] % 2;
                q.push(v);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << col[i] << '\n';
    }
    return 0;
}