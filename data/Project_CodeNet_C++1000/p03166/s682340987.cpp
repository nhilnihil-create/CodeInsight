#include <bits/stdc++.h> 
using namespace std; 
long long int n,m;
int solve(int source,vector<int> v[],vector<int> &dp)
{
    
    int count=0;
    if(dp[source]!=-1)
    return dp[source];
    for(int i=0;i<(int)v[source].size();i++)
    {
       count=max(count,1+solve(v[source][i],v,dp));
    }
    return dp[source]=count;
}
int main()
{
    cin>>n>>m;
    int x,y;
    vector<int> v[n+1];
    for(long long int i=0;i<m;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
    }
    int source=1;
   // vector<vector<long long int> > dp( n , vector<long long int> (w+1, -1));
   vector<int> dp(n+1,-1);
   int maxx=0;
   for(int i=1;i<=n;i++)
   {
      if(dp[i]==-1)
      {
        int m=solve(i,v,dp);
        //cout<<m<<endl;
        if(m>=maxx)
        maxx=m;
      }
   }
     cout<<maxx<<endl;
    //cout<<maxx<<endl;
}


