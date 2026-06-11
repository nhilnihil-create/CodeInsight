#include<bits/stdc++.h>
#define int long long 
#define mod 1000000007
using namespace std;
int n;
int dp[100001][2];
vector<int>adj[100001];
int solve(int u ,int par ,int c)
{
     if(dp[u][c]!= -1)
      return dp[u][c];
     int ans  = 0;
     
     bool leaf = true;
      
      int w1 = 1;int w2 =1;
     for(auto child : adj[u])
     {
         if(child!= par)
         {
            leaf = false;

            w1 = (w1*solve(child,u,0))%mod;

            if(!c)
              {
                  w2 = (w2*solve(child,u,1))%mod;
              }
         }
     }

       ans = w1;
       if(!c)
        ans = (ans+w2)%mod;

      return dp[u][c] = ans;

}
signed main(void)
{
    memset(dp , -1 ,sizeof dp);
    cin>>n;
    int a,b;
    for(int  i = 0;i<(n-1);i++)
    {
      cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    cout<<solve(1,-1,0)<<endl;
}