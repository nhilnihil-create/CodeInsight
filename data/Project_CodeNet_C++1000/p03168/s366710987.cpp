#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'
#define inf 1e18
#define mod 1e9+7

double dp[3005][3005];
double ar[3005];
void testCase()
{
   // ll t; cin>>t; while(t--)
    {
      ll n;
      cin>>n;
      for(int i=0;i<n;i++)
      cin>>ar[i];

      dp[0][0]=(1-ar[0]);
      dp[0][1]=ar[0];

      for(int i=1;i<n;i++)
      {
          for(int j=0;j<3000;j++)
          {
              dp[i][j]+=dp[i-1][j]*(1-ar[i]);
              if(j>0)
              dp[i][j]+=dp[i-1][j-1]*ar[i];
          }
      }
      double ans=0;
      for(int i=n/2+1;i<3000;i++)
      ans+=dp[n-1][i];
      cout<<setprecision(9);
      cout<<fixed;
      cout<<ans<<endl;
    } 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    testCase();
    return 0;
}