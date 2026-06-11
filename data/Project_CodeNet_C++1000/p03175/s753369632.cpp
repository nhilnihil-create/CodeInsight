#include<bits/stdc++.h>

using namespace std;

void dfs(vector<vector<long long int>> &dp,vector<vector<long long int>> &adj,long long int i,long long int parent){
  dp[i][0] = 1;
  dp[i][1]=1;
  for(auto e: adj[i]){   
    if(e == parent) continue;
    dfs(dp,adj,e,i);
    dp[i][1] = ((dp[i][1]%1000000007) * (dp[e][0]%1000000007))%1000000007;
    dp[i][0] = ((dp[i][0]%1000000007) * ((dp[e][0]%1000000007 + dp[e][1]%1000000007)%1000000007))%1000000007;
  }
  return;
}

int main(){
  int n;
  long long int a,b;
  cin >> n;
  vector<vector<long long int>> adj(n+1);
  for(int i=0;i<n-1;i++){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  vector<vector<long long int>> dp(n+1,vector<long long int>(2,0));
  dfs(dp,adj,1,-1);
  cout << (dp[1][0] + dp[1][1])%1000000007 << endl;
  return 0;
}
