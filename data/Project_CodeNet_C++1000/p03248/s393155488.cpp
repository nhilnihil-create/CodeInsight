#include <iostream>
#include <string>
#include <set>
#include <vector>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using P = std::pair<int, int>;

std::string s;
std::set<int> vs;
std::vector<P> ps;

int main()
{
  std::cin >> s;

  int n = s.size();

  rep( i, n ) if( s[i] == '1' )
  {
    vs.emplace( i+1 );

    if( i == n-1 )
    {
      puts("-1");

      return 0;
    }
  }

  if( vs.empty() )
  {
    puts("-1");

    return 0;
  }

  vs.emplace( n );

  int ptr = 1, pnxt = 0;

  for( auto it = vs.begin(); it != vs.end(); ++it )
  {
    if( *it-n && !vs.count(n-*it) )
    {
      puts("-1");

      return 0;
    }

    int diff = *it;
    int cnt = ptr;
    
    rep( d, diff-cnt )
      ps.emplace_back( P( pnxt, ptr++ ) );

    if( *it-n )
      ps.emplace_back( P( pnxt, ptr ) );

    pnxt = ptr++;
  }

  for( auto p : ps )
    printf( "%d %d\n", p.first+1, p.second+1 );

  return 0;
}