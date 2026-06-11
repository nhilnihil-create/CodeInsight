#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> v;
    for(int i=0;i<n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        v.push_back({x,y,z});

    }
   long dp[n][3];
   dp[0][0]=v[0][0];
   dp[0][1]=v[0][1];
   dp[0][2]=v[0][2];
   for(int i=1;i<n;i++)
   {
       for(int j=0;j<3;j++){
        dp[i][j]=v[i][j]+max(dp[i-1][(((j-1)+3)%3)],dp[i-1][(((j+1)+3)%3)]);
       }
   }
    long ans=max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
    cout<<ans;

    return 0;
}
