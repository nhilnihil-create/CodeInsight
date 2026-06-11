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
using P = std::pair<int, int>;

ll N;
std::vector<P> ps;

int main()
{
  std::cin >> N;

  if( N % 2 == 0 )
  {
    rep( i, N )
    {
      repi( j, i+1, N ) if( i != j && i+j != N-1 )
      {
        ps.emplace_back( P( i+1, j+1 ) );
      }
    }
  }
  else
  {
    rep( i, N )
    { 
      repi( j, i+1, N ) if( j == N-1 || i+j != N-2 )
      {
        ps.emplace_back( P( i+1, j+1 ) );
      }
    }
  }

  std::cout << ps.size() << std::endl;

  for( auto p : ps )
    std::cout << p.first << ' ' << p.second << std::endl;

  return 0;
}