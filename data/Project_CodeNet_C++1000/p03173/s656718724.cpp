#include<bits/stdc++.h>
using namespace std;
# define ll long long int
# define inf (1ll<<60)
ll dp[401][401];
ll add[401][401];

ll solve(ll arr[],int s,int e)
{
  if(s==e)
  {
    return 0;
  }
  if(dp[s][e]!=-1)
  {
    return dp[s][e];
  }
  ll min1= inf;
  for(int k=s;k<e;k++)
  {
    min1=min(min1,add[s][e]+solve(arr,s,k)+solve(arr,k+1,e));

  }

return dp[s][e]= min1;

}

void preprocessor(ll arr[],ll n)
{
  for(int i=0;i<n;i++)
  {
    for(int j=i;j<n;j++)
    {
      add[i][j]= arr[j] +((j==i)? 0: add[i][j-1]);
    }
  }
}

int main()
{
  ll n;
  cin>>n;
  ll arr[n];
  memset(dp,-1,sizeof(dp));
  for(ll i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  preprocessor(arr,n);
  cout<<solve(arr,0,n-1)<<endl;

}
