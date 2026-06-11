#include<bits/stdc++.h>
#include <iostream>
using namespace std;
const unsigned int M = 1000000007;
int main() {
    int n,m;
    cin>>n>>m;

    vector<vector<char>> matrix(n,vector<char>(m));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matrix[i][j];
        }
    }

    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));

    dp[n-1][m-1]=1;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(i==n-1 && j==m-1)
            {
                continue;
            }
            if(matrix[i][j]=='#')
            {
                dp[i][j]=0;
            }
            else
            {
                dp[i][j]=(dp[i+1][j]%M+dp[i][j+1]%M)%M;
            }
        }
    }
    cout<<dp[0][0]<<endl;
    return 0;
}
