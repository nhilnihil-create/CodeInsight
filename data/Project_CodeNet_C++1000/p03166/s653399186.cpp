#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[100001];
bool visited[100001];
vector<int> graph[100001];
int ans;
void dfs(int node){
    visited[node] = true;
    if(graph[node].empty()){ dp[node] = 0; return;}
    int maxa =0;
    for(auto i : graph[node]){
        if(!visited[i]){
            dfs(i);
        }
        maxa = max(maxa, dp[i]);
    }
    dp[node] = 1 + maxa;
}
int n, m;
int main(){
    cin>>n>>m;
    while(m--){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    int ans = 0;
    for(int x=1;x<=n;x++){
        dfs(x);
        ans = max(ans, dp[x]);
    }
    cout<<ans;

}
