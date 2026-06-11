#include <bits/stdc++.h>
using namespace std;

#define pb(a) push_back(a)
#define vi vector<int>
#define loop(i, n) for(int i=1;i<=n;i++)
#define loop0(i, n) for(int i=0;i<n;i++)
#define in(i) scanf("%d", &i);
#define out(i) printf("%d", i)
#define inc(i) scanf("%c", &i)

int h, w, lastI=INT_MIN, lastJ=INT_MIN;
char grid[1001][1001];
int dp[1001][1001];
const int mod=1000000007;

int solve(int x, int y)
{
  if(x==h && y==w)
    return 1;
  if(grid[x][y]!='.')
    return 0;
  if(dp[x][y]!=-1)
    return dp[x][y];
  if(x==h || grid[x+1][y]=='#')
    return dp[x][y]=solve(x, y+1)%mod;
  if(y==w || grid[x][y+1]=='#')
    return dp[x][y]=solve(x+1, y)%mod;
  return dp[x][y]=(solve(x+1, y)%mod+solve(x, y+1)%mod)%mod;
}
int main()
{
  memset(dp, -1, sizeof(dp));
  in(h);
  in(w);
  loop(i, h)
  {
    loop(j, w)
    {
      cin>>grid[i][j];
      if(i==h && grid[i][j]=='#')
        lastJ=j;
      if(j==w && grid[i][j]=='#')
        lastI=i;
    }
  }
  cout<<solve(1, 1);
}

