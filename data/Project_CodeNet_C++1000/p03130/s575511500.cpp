#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;
std::vector<ll> G[5];
bool used[5];

bool dfs( ll v )
{
  used[v] = true;

  if( used[0] && used[1] && used[2] && used[3] )
  {
    puts("YES");

    return true;
  }

  for( auto u : G[v] ) if( !used[u] )
    if( dfs( u ) ) return true;

  used[v] = false;

  return false;
}

int main()
{
  rep( i, 3 )
  {
    int a, b;
    std::cin >> a >> b;

    --a; --b;

    G[a].emplace_back( b );
    G[b].emplace_back( a );
  }

  rep( v, 4 ) 
  {
    bool f = dfs(v);

    if( f )
    {
      return 0;
    }
  }

  puts("NO");

  return 0;
}