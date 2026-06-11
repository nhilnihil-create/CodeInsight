#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <functional>
#include <numeric>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

constexpr int MAX_N = 100000;

using ll = long long;

ll N;
ll L[MAX_N], R[MAX_N];
std::vector<ll> ls = { 0 }, rs = { 0 };

int main()
{
  scanf( "%lld", &N );
  rep( i, N )
  {
    scanf( "%lld%lld", L+i, R+i );

    ls.push_back( L[i] );
    rs.push_back( R[i] );
  }

  std::sort( ls.rbegin(), ls.rend() );
  std::sort( all(rs) );

  // 5,3,1,0
  // 0,2,4,6

  ll rS = 0, lS = 0;
  ll ans = 0;
  rep( k, N )
  {
    if( ls[k] > rs[k] )
    {
      lS += ls[k];
      rS += rs[k];
    }

    ans = std::max( ans, 2*(lS-rS) );
  }

  printf( "%lld\n", ans );

  return 0;
}