#include <bits/stdc++.h>
//#include<string>
using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<vector<int>> ar(n,vector<int>(3));
    for(int i=0;i<n;++i)
    {
        cin>>ar[i][0]>>ar[i][1]>>ar[i][2];

    }
    vector<vector<int>> dp(n,vector<int>(3,0));
    dp[0][0]=ar[0][0];
    dp[0][1]=ar[0][1];
    dp[0][2]=ar[0][2];
    for(int i=1;i<n;++i)
    {
        for(int j=0;j<3;++j)
        {
            for(int k=0;k<3;++k)
            {    if(j==k)
                continue;
                
                dp[i][j]=max(dp[i][j],ar[i][j]+dp[i-1][k]);
            }
        }
    }
    cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]})<<'\n';
 }

