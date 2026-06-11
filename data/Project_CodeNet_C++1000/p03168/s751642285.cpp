#include <bits/stdc++.h>
using namespace std;

#define pb(a) push_back(a)
#define vi vector<int>
#define loop(i, n) for(int i=1;i<=n;i++)
#define loop0(i, n) for(int i=0;i<n;i++)
#define in(i) scanf("%d", &i);
#define out(i) printf("%d", i)

int n;
double a[3001];
double dp[3001][3001];

int main()
{
  in(n);
  double ans=0;
  dp[0][0]=1.0;
  loop(i, n)
  {
    scanf("%le", &a[i]);
    dp[i][0]=dp[i-1][0]*(1-a[i]);
    loop(j, i)
    {
      dp[i][j]+=dp[i-1][j-1]*a[i] +dp[i-1][j]*(1-a[i]);
    }
  }
  for(int i=n/2+1;i<=n;i++)
    ans+=dp[n][i];
  cout<<setprecision(10)<<ans<<"\n";
}
