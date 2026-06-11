#include <bits/stdc++.h>
using namespace std;
vector<int> t[100005];
long long int dp[100005][2];
long long int m=1000000007;
long long int solve(int node,bool constraint,int par)
{
   long long  int ans=0;
    long long int w1=1;
    if(dp[node][constraint]!=-1)
    {
        return dp[node][constraint];
    }
    for(auto child:t[node])
    {
        if(child!=par)
        {
            w1=w1*solve(child,0,node);
            w1=w1%m;
        }
    }
    ans=ans+w1;
    if(constraint!=1)
    {
        long long int w2=1;
        for(auto child:t[node])
        {
            if(child!=par)
            {
                w2=w2*solve(child,1,node);
                w2=w2%m;
            }
         }
         ans=ans+w2;
         ans=ans%m;
    }
    return dp[node][constraint]=ans;
}
int main() {
    int n;
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    long long int ans=solve(1,0,-1);
    cout<<ans<<endl;
	return 0;
}