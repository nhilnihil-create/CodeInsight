#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define all(a) (a).begin(),(a).end()
#define X first
#define Y second
#define inf 2e9+5
using namespace std;
const int mod=1e9+7;
void solve()
{
  int n,k; cin>>n>>k; int a[n];
  for(int i=0;i<n;i++)cin>>a[i];
  int dp[k+1]={0}; dp[0]=1;
  for(int i=0;i<n;i++)
  {
      int cnt=0;
      for(int j=k;j>=k-a[i];j--){cnt+=dp[j]; cnt%=mod;}
      for(int j=k;j>=0;j--)
      {
          int t=dp[j];
          dp[j]=cnt;
          cnt-=t;
          if(j-a[i]-1>=0)cnt+=dp[j-a[i]-1];
          cnt=(cnt+mod)%mod;
      }
  }
  cout<<dp[k];
  return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; t=1;
    while(t--)solve();
    return 0;
}
