#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
 
void solve(){
    int n,m,u,v;
    cin>>n>>m;
    vector<vector<int>> adj(n+1,vector<int>());
    vector<int> indegree(n+1,0);
    for(int i=0;i<m;++i){
        cin>>u>>v;
        adj[u].push_back(v);
        ++indegree[v];
    }
    vector<bool> done(n+1,false);
    vector<int> dp(n+1,0);
    for(int i=1;i<=n;++i){
        if(!indegree[i] && !done[i]){ 
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                u=q.front();   q.pop();
                for(int v : adj[u]){
                    if(indegree[v]){
                        dp[v]=max(dp[v],dp[u]+1);
                        --indegree[v];
                        if(!indegree[v]){
                            done[v]=true;
                            q.push(v);
                        }
                    } 
                }
            }
        } 
    }
    cout<<*max_element(dp.begin(),dp.end());
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    solve(); cout<<endl;
    return 0;
}