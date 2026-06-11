#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;

const std::string LRUD = "LRUD";
const ll dj[4] = { -1, 1, 0, 0 }, di[4] = { 0, 0, -1, 1 };

ll H, W, N, sr, sc;
std::string S, T;

int main()
{
  std::cin >> H >> W >> N >> sr >> sc >> S >> T;

  --sr, --sc;

  ll l = 0, r = W;

  if( S[N-1] == 'L' )
    ++l;
  else if( S[N-1] == 'R' )
    --r;

  for( int i = N-2; i >= 0; --i )
  { 
    if( T[i] == 'L' )
      r = std::min( r+1, W );
    else if( T[i] == 'R' )
      l = std::max( l-1, 0ll );

    if( r-l <= 0 )
    {
      puts("NO");

      return 0;
    }

    if( S[i] == 'L' )
      ++l;
    else if( S[i] == 'R' )
      --r;

    if( r-l <= 0 )
    {
      puts("NO");

      return 0;
    }
  }

  if( !(l <= sc && sc < r) )
  {
    puts("NO");

    return 0;
  }

  l = 0, r = H;

  if( S[N-1] == 'U' )
    ++l;
  else if( S[N-1] == 'D' )
    --r;

  for( int i = N-2; i >= 0; --i )
  {

    if( T[i] == 'U' )
      r = std::min( r+1, H );
    else if( T[i] == 'D' )
      l = std::max( l-1, 0ll );

    if( r-l <= 0 )
    {
      puts("NO");

      return 0;
    }

    if( S[i] == 'U' )
      ++l;
    else if( S[i] == 'D' )
      --r;

    if( r-l <= 0 )
    {
      puts("NO");

      return 0;
    }
  }

  if( !(l <= sr && sr < r) )
  {
    puts("NO");

    return 0;
  }

  puts("YES");

  return 0;
}