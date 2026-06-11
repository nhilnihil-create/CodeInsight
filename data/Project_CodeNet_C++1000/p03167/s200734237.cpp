#include<bits/stdc++.h>
using namespace std;
int main()
{
 int rows,cols;
  cin>>rows>>cols;
  char input[rows][cols];
    int co=1e9+7;
  for(int i=0;i<rows;i++)
  {
 for(int j=0;j<cols;j++)
   cin>>input[i][j];
  }
  int dp[rows][cols];
  memset(dp,0,sizeof(dp));
dp[rows-1][cols-1]=1;
    for(int i=cols-2;i>=0;i--)
  {
   if(input[rows-1][i]=='.')
    dp[rows-1][i]=dp[rows-1][i+1];
     else
           dp[rows-1][i]=0;
       
  }
    for(int i=rows-2;i>=0;i--)
  {
   if(input[i][cols-1]=='.')
    dp[i][cols-1]=dp[i+1][cols-1];
     else
           dp[i][cols-1]=0;
       
  }
  for(int i=rows-2;i>=0;i--)
  {
   for(int j=cols-2;j>=0;j--)
   {
 if(input[i][j]=='.')
    dp[i][j]=(dp[i+1][j]+dp[i][j+1])%co;
     else
           dp[i][j]=0;
     
   }
  }
   // for(int i=0;i<rows;i++)
   // {
   //     for(int j=0;j<cols;j++)
   //         cout<<dp[i][j]<<" ";
   //     cout<<endl;
   // }
cout<<dp[0][0]<<endl;
}