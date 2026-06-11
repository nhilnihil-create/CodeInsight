#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 1;
vector<int> adj[maxN];
int indegree[maxN], startTime[maxN], dp[maxN], endTime[maxN];
bitset<maxN> visited;
int dfs(int u, int timing){
    if(visited[u]){
        return endTime[u];
    }
    startTime[u] = timing;
    visited[u] = true;
    int k = 0;
    for(auto v : adj[u])
        k = max(k, dfs(v, timing + 1) + 1);
    dp[u] = startTime[u] + k;
    endTime[u] = k;
    return k;
}
int main( ){
    int n, m, x, y;
    scanf("%d %d", &n, &m);
    while(m--){
        cin >> x >> y;
        adj[x].emplace_back(y);
        indegree[y]++;
    }
    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0 && !visited[i]){
            dfs(i, 0);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}