#include <bits/stdc++.h>
#define mp make_pair
#define f1 first
#define f2 second
#define int long long
#define int1 int
#define pb push_back
using namespace std;
int dp[309][309][309];
main()
{
  string s;
  cin>>s;
  int k;
  cin>>k;
  int n=s.size();
  for(int i=0 ; i<n ; i++)
  {
      for(int j=0 ; j<=k ; j++)
      {
          dp[i][i][j]=1;
      }
  }
  for(int j=1 ; j<n ; j++)
  {
      for(int i=j-1 ; i>=0 ; i--)
      {
          for(int w=0 ; w<=k ; w++)
          {
              if(s[i]==s[j])
              {
                  dp[i][j][w]=dp[i+1][j-1][w]+2;
              }
              else if(w==0)
              {
                  dp[i][j][w]=max(dp[i+1][j][w],dp[i][j-1][w]);
              }
              else
              {
                dp[i][j][w]=max(max(dp[i+1][j][w],dp[i][j-1][w]),dp[i+1][j-1][w-1]+2);
              }
          }
      }
  }

cout<<dp[0][n-1][k];
}
