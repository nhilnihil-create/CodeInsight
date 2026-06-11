#include <bits/stdc++.h>
using namespace std;
long long n,m;
vector <pair<long long, long long>> vertice;
vector <vector<long long>> graph;
vector <long long> dp;
long long dfs(long long root){
    if(graph[root].size()==0){
        dp[root] = 0;
    }else{
        long long tmp = 0;
        for(long long i = 0; i < graph[root].size(); i++){
            if(dp[graph[root][i]]==-1){
                tmp = max(tmp,dfs(graph[root][i]));
            }else{
                tmp = max(tmp,dp[graph[root][i]]);
            }
        }
        dp[root] = tmp + 1;
    }
    return dp[root];
}
int main(){
    cin >> n >> m;
    vertice = vector <pair<long long, long long>>(m,{0,0});
    graph = vector <vector<long long>>(n,vector<long long>());
    dp = vector<long long>(n,-1);
    for(long long i = 0; i < m; i++){
        cin >> vertice[i].first;//root
        cin >> vertice[i].second;//leaf
        vertice[i].first--;
        vertice[i].second--;
    }
    for(long long i = 0; i < m; i++){
        graph[vertice[i].first].push_back(vertice[i].second);
    }
    vector <long long> ans(n);
    for(long long i = 0; i < n; i++){
        ans[i] = dfs(i);
    }
    sort(ans.begin(),ans.end());
    cout << ans.back() << endl;
        
    return 0;
}