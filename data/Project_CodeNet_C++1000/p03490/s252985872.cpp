#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define clr(a,v) memset((a),(v),sizeof(a))

std::string s;
int x, y;
bool fl;
std::vector<int> vs[2];
bool dp[2][20010];

int main()
{
  std::cin >> s >> x >> y;

  int cnt = 0;
  rep( i, s.size() )
  {
    if( s[i] == 'F' )
      ++cnt;
    else
    {
      vs[fl].push_back( cnt );
      cnt = 0;
      fl ^= true;
    }
  }

  if( cnt )
    vs[fl].push_back( cnt );

  bool ans = true;

  dp[0][10000] = true;
  rep( i, vs[0].size() ) 
  {
    rep( j, 20001 )
      dp[(i+1)%2][j] = false;

    rep( j, 20001 )
    {
      if( j+vs[0][i] < 20000 )
        dp[(i+1)%2][j+vs[0][i]] |= dp[i%2][j];

      if( i && j-vs[0][i] >= 0 )
        dp[(i+1)%2][j-vs[0][i]] |= dp[i%2][j];
    }
  }

  if( !dp[vs[0].size()%2][x+10000] )
    ans = false;

  clr( dp, false );
  dp[0][10000] = true;
  rep( i, vs[1].size() )
  {
    rep( j, 20001 )
      dp[(i+1)%2][j] = false;

    rep( j, 20001 )
    {
      if( j+vs[1][i] <= 20000 )
        dp[(i+1)%2][j+vs[1][i]] |= dp[i%2][j];
      if( j-vs[1][i] >= 0 )
        dp[(i+1)%2][j-vs[1][i]] |= dp[i%2][j];
    }
  }

  if( !dp[vs[1].size()%2][y+10000] )
    ans = false;

  std::cout << (ans ? "Yes" : "No") << std::endl;

  return 0;
}