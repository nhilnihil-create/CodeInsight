#include<bits/stdc++.h>
using namespace std;

long double dp[303][303][303];

int main()
{
 int n;
 cin >> n;

 int c1=0, c2=0, c3=0;
 for(int i=0, x; i<n; i++)
 {
  cin >> x;
  if(x == 1) c1++;
  if(x == 2) c2++;
  if(x == 3) c3++;
 }

 long double pi,pj,pk,wt;
 for(int i=0; i<=n; i++)
 {
  for(int j=0; i+j<=n; j++)
  {
    for(int k=0; i+j+k<=n; k++)
    {
      if(i==0 && j==0 && k==0)
      continue;

      pi = 1.0*i/(i+j+k);
      pj = 1.0*j/(i+j+k);
      pk = 1.0*k/(i+j+k);
      wt = 1.0*n/(i+j+k);

      if(k)
        dp[k][j][i] += dp[k-1][j][i]*1.0*pk;
      if(j)
        dp[k][j][i] += dp[k+1][j-1][i]*1.0*pj;
      if(i)
        dp[k][j][i] += dp[k][j+1][i-1]*1.0*pi;

      dp[k][j][i] += wt;
    }
  }
 }
  
 cout<<setprecision(17)<<dp[c1][c2][c3];

  return 0;
}
