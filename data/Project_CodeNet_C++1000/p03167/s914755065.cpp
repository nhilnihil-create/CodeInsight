#include<bits/stdc++.h>
using namespace std;

int main()
{
  long long int i,j,n,k,m,mod=1000000007;
  cin>>n>>m;
  vector<vector<char>>inp(n+1,vector<char>(m+1));
  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
     cin>>inp[i][j];
  vector<vector<long long int>>v(n+1,vector<long long int>(m+1,0));
  v[1][1]=1;
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=m;j++)
   {
    if(i==1&&j==1)
     continue;
    if(inp[i][j]!='#')
     v[i][j]=(v[i-1][j]+v[i][j-1])%mod;
   }
  }
  cout<<v[n][m];
 return 0;
}