#include <bits/stdc++.h>
using namespace std;
vector<list<int>> v(100005);
vector<int> dp(100005,-1);
// vector<int> isvisited(100005);
int n,m;
int dfs(int i)
{
    int ans = 0;
    for(auto nbr:v[i])
    {
        if(dp[nbr]==-1)
        {
            ans = max(ans,1+dfs(nbr));
        }
        else{
            ans = max(ans,dp[nbr]+1);
        }
    }
    return dp[i] = ans;
}
int main() {
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
    }
    for(int i=1;i<=n;i++)
    {
        if(dp[i]==-1)
        {
            dp[i] = dfs(i);
        }
    }
    int res=0;
    for(int i=1;i<=n;i++)
    res = max(res,dp[i]);
    cout<<res;
}
