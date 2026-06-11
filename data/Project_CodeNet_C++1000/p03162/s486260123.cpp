#include<bits/stdc++.h>
#define int long long int
#define pb push_back
#define inf 1e9
#define pp pop_back
#define pii pair<int,int>
#define vec vector<int>
#define mp make_pair
using namespace std;
int a[100001],b[100001],c[100001];
int dp[100001][4];
int ans(int n,int x)
{
  if(n==0)
     return 0;
  if(dp[n][x]!=-1)
    return dp[n][x];
  if(x==0)
    return dp[n][x]=max(a[n]+ans(n-1,1),max(b[n]+ans(n-1,2),c[n]+ans(n-1,3)));
  else if(x==1)
    return dp[n][x]=max(b[n]+ans(n-1,2),c[n]+ans(n-1,3));
  else if(x==2)
    return dp[n][x]=max(a[n]+ans(n-1,1),c[n]+ans(n-1,3));
  else
    return dp[n][x]=max(a[n]+ans(n-1,1),b[n]+ans(n-1,2));
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t=1;
  //cin>>t;
  while(t--)
  {
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    int i;
    for(i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i];
    cout<<ans(n,0);
  }
}
