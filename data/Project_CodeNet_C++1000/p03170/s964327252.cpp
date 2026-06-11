#include<bits/stdc++.h>

using namespace std;
int dp[100005];
bool pro(vector<int> a, int k)
{
  if(k==0)
    return false;
  if(dp[k]!=-1)
    return dp[k];
  bool ans=false;
  int n=a.size();
  for(int i=0;i<n;i++)
  {
    if(k-a[i]>=0 && !pro(a,k-a[i]))
    {
      ans=true;
      break;
    }
  }
  return dp[k]=ans;
}

int main()
{
  int n,k;
  cin>>n>>k;
  vector<int> a(n);
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  memset(dp,-1,sizeof(dp));
  cout<<(pro(a,k)?"First":"Second")<<endl;
  return 0;
}
