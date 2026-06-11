#include<bits/stdc++.h>
using namespace std;
long long dp[100005][5];
int main()
{
     int n,x,y,z,p,q,i;
     cin>>n;
     cin>>dp[1][1]>>dp[1][2]>>dp[1][3];
     for(i=2; i<=n; i++)
     {
            cin>>x>>y>>z;
            dp[i][1]=x+max(dp[i-1][2],dp[i-1][3]);
            dp[i][2]=y+max(dp[i-1][1],dp[i-1][3]);
            dp[i][3]=z+max(dp[i-1][2],dp[i-1][1]);
     }
       cout<< max(max(dp[n][1],dp[n][2]),dp[n][3])<<endl;
       return 0;
}
