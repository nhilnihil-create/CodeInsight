#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

int main()
{
  ll n,k;
  cin>>n>>k;
  vector<ll> arr(n),dp(n,INT_MAX);
  for(int i=0;i<n;i++)
    cin>>arr[i];

  dp[0]=0;
  for(int i=1;i<n;i++)
  {
    int count=0;
    for(int j=i-1;j>=0&&count<k;j--)
    {
      dp[i]=min(dp[i],abs(arr[i]-arr[j])+dp[j]);
      count++;
    }
  }
  cout<<dp[n-1]<<endl;

}
