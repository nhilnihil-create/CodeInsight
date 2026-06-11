#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long int 
int dp[100100][3];
vector<vector<int>> g;
int solve(int u,int col,int parent)
{  if(dp[u][col]!=-1)
    {return dp[u][col];}

    int var=1;

for(int i=1;i<g[u].size();i++)
    { int v=g[u][i];
        if(v!=parent)
        {  int temp=0;
              if(col==1)
            { temp+=(solve(v,1,u)%mod);
            temp=temp%mod;
                temp+=(solve(v,2,u)%mod);
                 temp=temp%mod;
            }
            else
            {
                 temp+=(solve(v,1,u)%mod);
                  temp=temp%mod;
            }
            var=var%mod;
            var=var*temp;
            var=var%mod;
        }
    }


    dp[u][col]=var;
    return var;
}

signed main()
{ int n;
  cin>>n;
  vector<int> g1;
  g1.push_back(-1);
  for(int i=0;i<=n;i++)
    {g.push_back(g1);}

    int u,v;
  for(int i=1;i<n;i++)
    { cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(dp,-1,sizeof(dp));
    int ans=0;

    ans+=solve(1,1,-1);
    ans=ans%mod;
   // memset(dp,-1,sizeof(dp));
    ans+=solve(1,2,-1);
    ans=ans%mod;

    cout<<ans;
}
