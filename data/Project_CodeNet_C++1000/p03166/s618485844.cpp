#include <iostream>
#include<bits/stdc++.h>

#define ll long long
using namespace std;

void dfs(int vtx , vector<int>& dp , vector<vector<int>>& g,int par)
{
    dp[vtx] = 0;
   
    for(int x : g[vtx])
    {
        if(x == par)
          continue;
    
        if(dp[x] ==  -1)
          dfs(x , dp , g , vtx);

         dp[vtx] =  max(dp[x] + 1 , dp[vtx]);
    }

}
int main()
{
    
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>>g(n+1);
    for(int i = 0 ; i<m ;i++)
    {
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
    }
   
    vector<int>dp(n+1 , -1);

    int omax = 0;
    for(int i = 1 ; i<= n ;i++)
    {

        if(dp[i] == -1)
        dfs(i , dp , g , -1);
    }
    
    for(int i = 1 ; i<= n; i++)
     omax = max(omax , dp[i]) ;

    cout<<omax<<endl;
}