#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back


int solve(vector<int> &a,vector<vector<int>>&dp,ll k,int t)
{
  if(dp[k][t]>-1)
    return dp[k][t];

  int winner=-1;
  for(int i=0;i<a.size();i++)
  {
    if(a[i]<=k)
    {
      int win=solve(a,dp,k-a[i],1-t);
      if(win==t)
        winner=t;
    }
  }
  if(winner==-1)
      winner=1-t;
  return dp[k][t]=winner;
}

int main()
{
  ll n,k;
  cin>>n>>k;
  vector<int> a(n);
  for(int i=0;i<n;i++)
    cin>>a[i];
  vector<vector<int>>dp(k+1,vector<int>(2,-1));

  int p=solve(a,dp,k,0);
  if(p==0)
      cout<<"First\n";
  else
      cout<<"Second\n";
}
