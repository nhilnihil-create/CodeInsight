// Author: Sayantanu
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
const int mod = 1e9 + 7;

vector<int> dp(1e5+1,-1);
vector<int> adj[(int)(1e5+ 1)];

int ans(int node){
    if(adj[node].size()==0){
        dp[node] = 0;
        return dp[node];
    }
    if(dp[node]!=-1)return dp[node];
    int a = -1;
    for(auto i: adj[node]){
        a = max(a,ans(i));
    }
    dp[node] = 1 + a;
    return dp[node];
}

int main() {
    //code
    int n,m;
    cin>>n>>m;
    int u,v;
    while(m--){
        cin>>u>>v;
        adj[u].push_back(v);
    }
    int an = 0;
    for(int i = 1;i <=n;i++)an = max(an,ans(i));
    cout<<an;
    return 0;
}