#include<bits/stdc++.h>
#define int long long int
#define pb push_back
#define inf 1e9
#define pp pop_back
#define pii pair<int,int>
#define vec vector<int>
#define mp make_pair
using namespace std;
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t=1;
  //cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int i;
    int a[n+1],b[n+1],c[n+1];
    for(i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i];
    int dp[n+1][4];
    dp[0][0]=dp[0][1]=dp[0][2]=dp[0][3]=0;
    for(i=1;i<=n;i++)
    {
      dp[i][0]=max(a[i]+dp[i-1][1],max(b[i]+dp[i-1][2],c[i]+dp[i-1][3]));
      dp[i][1]=max(b[i]+dp[i-1][2],c[i]+dp[i-1][3]);
      dp[i][2]=max(a[i]+dp[i-1][1],c[i]+dp[i-1][3]);
      dp[i][3]=max(a[i]+dp[i-1][1],b[i]+dp[i-1][2]);
    }
    cout<<dp[n][0];
  }
}
