#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define F first
#define S second
#define mod 1000000007

int main()
{
  ll h,w;
  cin>>h>>w;
  vector<vector<char>>mat(h,vector<char>(w,'.'));

  for(int i=0;i<h;i++)
  {
    for(int j=0;j<w;j++)
      cin>>mat[i][j];
  }

  vector<vector<ll>>dp(h,vector<ll>(w,0));
  dp[h-1][w-1]=0;
  for(int i=w-2;i>=0;i--)
  {
    if(mat[h-1][i]=='.')
      dp[h-1][i]=1;
    else
        break;
  }
  for(int i=h-2;i>=0;i--)
  {
    if(mat[i][w-1]=='.')
      dp[i][w-1]=1;
    else
        break;
  }

  for(int i=h-2;i>=0;i--)
  {
    for(int j=w-2;j>=0;j--)
    {
      if(mat[i][j]=='.')
      {
        if(dp[i+1][j]>0&&dp[i][j+1]>0)
          dp[i][j]=(dp[i+1][j]+dp[i][j+1])%mod;
        else
          dp[i][j]=(max(dp[i+1][j],dp[i][j+1]))%mod;
      }
    }
  }
  cout<<dp[0][0]<<endl;
}
