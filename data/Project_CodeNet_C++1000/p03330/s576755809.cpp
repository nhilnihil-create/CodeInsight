#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  int n,col;cin>>n>>col;
  vector<vector<int>> d(col,vector<int>(col));
  vector<vector<int>> c(n,vector<int>(n));
  vector<vector<int>> dot(3,vector<int>(col,0));
  int i,j,k,l;
  rep(i,col)rep(j,col)cin>>d[i][j];
  rep(i,n)rep(j,n)cin>>c[i][j];
  rep(i,n)rep(j,n)dot[(i+j)%3][c[i][j]-1]++;
  int ans=1000000000;
  for(i=0;i<col;i++)
  {
    for(j=0;j<col;j++)
    {
      if(j==i)continue;
      for(k=0;k<col;k++)
      {
        if(k==i||k==j)continue;
        int kans=0;
        for(l=0;l<col;l++)kans+=d[l][i]*dot[0][l];
        for(l=0;l<col;l++)kans+=d[l][j]*dot[1][l];
        for(l=0;l<col;l++)kans+=d[l][k]*dot[2][l];
        ans=min(ans,kans);
      }
    }
  }
  cout<<ans<<endl;
}
