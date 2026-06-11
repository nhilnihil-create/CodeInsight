#include <iostream>
#include<bits/stdc++.h>

using namespace std;
int solve(int ind,vector<int>&dp,vector<vector<int> >&G){
   // cout << ind << " "<<dp[ind] <<endl;
   if(dp[ind]!= -1){
    return dp[ind];
   }
   dp[ind]=1;
   for(int i=0;i<(int)G[ind].size();++i){
      int val=G[ind][i];
        dp[val]=solve(val,dp,G);
   }
   for(int i=0;i<(int)G[ind].size();++i)
    dp[ind]=max(dp[ind],1+dp[G[ind][i]]);
   return dp[ind];
}
int main()
{
    int n,m;
    cin >> n>> m;
    vector<vector<int> >G(n+1);
    for(int i=0;i<m;++i){
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
    }
    vector<int>dp(n+1,-1);
    for(int i=1;i<=n;++i){
        if(dp[i]==-1){
            dp[i]=solve(i,dp,G);
        }
    }
    int ans=1;
    for(int i=1;i<=n;++i){
        if(dp[i]>ans)
            ans=dp[i];
    }
    cout << ans-1 <<endl;
    return 0;

}
