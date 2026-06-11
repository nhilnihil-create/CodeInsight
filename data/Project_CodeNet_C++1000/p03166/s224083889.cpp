#include<bits/stdc++.h>
using namespace std;

int dfs(vector<int> edges[], vector<int> &dp, int sv){
    if(dp[sv] != -1)
        return dp[sv];
    int maxLen = 0;
    for(int neighbour: edges[sv]){
        int currLen = dfs(edges, dp, neighbour) + 1;
        if(currLen > maxLen)
            maxLen = currLen;
    }
    dp[sv] = maxLen;
    return maxLen;
}

int main()
{
 int n, m;
 cin>>n>>m;
 vector<int> edges[n];
 int u, v;
 for(int i=0; i<m; i++){
    cin>>u>>v;
    edges[u-1].push_back(v-1);
 }
 int maxLen = 0;
 vector<int> dp(n, -1);
 for(int i=0; i<n; i++){
    if(dp[i] == -1){
        int currLen = dfs(edges, dp, i);
        if(currLen > maxLen)
            maxLen = currLen;
    }
 }
 cout<<maxLen;
 return 0;
}

