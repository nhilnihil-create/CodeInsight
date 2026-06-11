#include<bits/stdc++.h>
using namespace std;
// problem G
const int MAX = 100005;
int visited[MAX], dp[MAX];
vector<int> adj[MAX];

int dfs(int v){

    //if the current vertex is already visited then it already have its max length from this 
    // vertex in the dp array, so we will simply return dp[v];
    if(visited[v])
        return dp[v];


    visited[v] = 1;  

    int best = 0;

    // we will check for every child of vertex;
    for(auto child : adj[v])
    {
        best = max(best, dfs(child) + 1);
    }

    // once done then return the best length from this particular vertex.
    return dp[v] = best;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    
    int n, m;
    cin>>n >> m;

    for(int i = 0 ; i< m ; i++){
        int x, y;
        cin>> x>>y;

        adj[x].push_back(y);
    }

    int ans = 0;

    // now we are running dfs for every unvisited vertex.

    for(int i = 1; i<=n; i++)
    {
        if(!visited[i])
        ans = max(ans, dfs(i));
    }

    cout<<ans<<endl;


    return 0;
}
