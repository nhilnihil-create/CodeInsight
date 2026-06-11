#include<bits/stdc++.h>
using namespace std;

#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<int, int> pi;
typedef pair<lli, lli> pii;

#define N 100010
vector<int> adj[N];
bitset<N>vis;
lli ans;
void bfs(int st)
{
    ans++;
    queue<int> qu;
    qu.push(st);
    vis[st] = 1;
    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        for(auto v: adj[u]){
            if(vis[v] == 0){
                vis[v] = 1;
                qu.push(v);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        if(vis[i] == 0){
            bfs(i);
        }
    }
    cout << ans << "\n";

    return 0;
}
