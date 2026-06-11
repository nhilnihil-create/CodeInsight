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

ll N;
ll F[100][20];
ll P[100][20];
ll ans = -(1ll<<60);

int main()
{
  std::cin >> N;
  rep( i, N ) rep( j, 5 ) rep( k, 2 )
    std::cin >> F[i][j*2+k];

  rep( i, N ) rep( j, 11 )
    std::cin >> P[i][j];

  rep( bit, 1<<10 )
  {
    std::vector<ll> vs;

    rep( b, 10 ) if( bit>>b&1 )
      vs.emplace_back( b );

    if( vs.empty() )
      continue;

    ll sum = 0;

    rep( i, N )
    {
      ll cnt = 0;

      for( auto v : vs )
      {
        if( F[i][v] )
          ++cnt;
      }

      sum += P[i][cnt];
    }

    chmax( ans, sum );
  }

  std::cout << ans << std::endl;

  return 0;
}