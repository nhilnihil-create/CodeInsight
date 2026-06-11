#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
#define mp make_pair
#define S second
#define F first
ll mod=1e9+7 ;
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define input_from_file  freopen("input.txt", "r", stdin);
using namespace std::chrono; 
ll dp[(1<<21)+1];
int main()
{
  // input_from_file 
  ll n;cin>>n;
  // cout<<n;
  ll vec[n][n];
  memset(dp,0,sizeof(dp));dp[0]=1;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)  cin>>vec[i][j];
  }
  for(int i=0;i<(1<<n);i++){
    ll m=__builtin_popcount(i);
    for(int j=0;j<n;j++)  {
      if(vec[m][j]==1 && (i&(1<<j))==0){
        dp[i|(1<<j)]+=dp[i];
        dp[i|(1<<j)]%=mod;
      }
    }
  }
  cout<<dp[(1<<n)-1]%mod<<endl;
  return 0;
}