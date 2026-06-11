#include <bits/stdc++.h>
using namespace std;
void solve()
{

 int row,col,mod=1e9+7;
 cin>>row>>col;
 string arr[row];
 for(int i=0;i<row;i++)
 {
    cin>>arr[i];
 }
 vector<vector<long long int>>dp(row,vector<long long int>(col,0));
dp[0][0]=1;
 for(int i=1;i<col;i++)
    if(arr[0][i]!='#')
    dp[0][i]=dp[0][i-1];


 for(int i=1;i<row;i++)
    if(arr[i][0]!='#')
    dp[i][0]=dp[i-1][0];


 for(int i=1;i<row;i++)
 {
     for(int j=1;j<arr[i].size();j++)
     {
        if(arr[i][j]!='#')
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
     }
 }

 /*for(int i=0;i<row;i++)
 {
     for(int j=0;j<col;j++)
     {
       cout<<dp[i][j]<<" ";
     }
     cout<<"\n";
 }*/
 cout<<dp[row-1][col-1];
}

int main()
{
    int test;
  //  cin>>test;
  test=1;
  while(test--)
  {
    solve();
  }


    return 0;
}
