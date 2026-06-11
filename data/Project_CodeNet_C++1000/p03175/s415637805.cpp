#include <bits/stdc++.h>
using namespace std;
const int LIM=1e5, MOD=1e9+7;
set<int> adjl[LIM+1];
vector<int> lvl(LIM+1,0);
long long int dp[LIM+1];
void dfs(int u)
{
    long long int white_ways=1, black_ways=1;
    for(int v: adjl[u])
    {
        if(lvl[v]==0)
        {
            lvl[v]=lvl[u]+1;
            dfs(v);
            white_ways*=dp[v];
            white_ways%=MOD;
            for(int w: adjl[v]) 
            {
                if(lvl[w]>lvl[v])
                {
                    black_ways*=dp[w];
                    black_ways%=MOD;
                }
            }
            dp[u]=(white_ways+black_ways)%MOD;
        }
    }
    if(adjl[u].size()==1 && u!=1) dp[u]=2;
}
int main()
{
    int n;
    cin>>n;
    if(n==1) 
    {
        cout<<2;
        return 0;
    }
    for(int i=1;i<n;i++)
    {
        int x, y;
        cin>>x>>y;
        adjl[x].insert(y);
        adjl[y].insert(x);
    }
    lvl[1]=1;
    dfs(1);
    cout<<dp[1];
}