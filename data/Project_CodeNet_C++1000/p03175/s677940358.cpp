#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007;
long long int dp[2][100005];

long long int sol(int color, int v, int prev, vector< vector<int>>&adj){
      if(dp[color][v]!=-1)return dp[color][v];
      long long int ans1=1, ans2=1;
      int cnt=0;
      for(auto u: adj[v]){
            if(u!=prev){
                  cnt++;
                  long long int p=0;
            
                  p+=sol(0, u, v, adj);
                  //else p+=sol(1, u, v, adj);
                  p%=mod;
                  ans1*=p;
                  ans1%=mod;
            }
      }
      if(!color)
      for(auto u: adj[v]){
            if(u!=prev){
                  cnt++;
                  long long int p=0;
            
                  p+=sol(1, u, v, adj);
                  //else p+=sol(1, u, v, adj);
                  p%=mod;
                  ans2*=p;
                  ans2%=mod;
            }
      }
      if(!color)ans1+=ans2;
      ans1%=mod;
      dp[color][v]=ans1;
      if(cnt==0){
            if(color)dp[color][v]=1;
            else dp[color][v]=2;
      }
      //cout<<color<<' '<<v<<' '<<dp[color][v]<<'\n';
      return dp[color][v];
}

int main(){
      int n;
      cin>>n;
      memset(dp, -1, sizeof(dp));

      vector< vector<int>>adj(n+1);
      for(int i=0; i<n-1; i++){
            int u, v;
            cin>>u>>v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
      }
      long long int ans=(sol(0, 0, -1, adj))%mod;
      cout<<ans<<'\n';
}