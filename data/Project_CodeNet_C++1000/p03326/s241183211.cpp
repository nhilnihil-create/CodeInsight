#include <cstdio>
#include <algorithm>
#include <vector>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;

ll N, M;
ll x[1010], y[1010], z[1010];

int main()
{
  scanf( "%lld%lld", &N, &M );

  rep( i, N )
    scanf( "%lld%lld%lld", x+i, y+i, z+i );

  ll ans = 0;

  rep( S, 1<<3 )
  {
    ll s1 = S&1 ? 1 : -1, s2 = S>>1&1 ? 1 : -1, s3 = S>>2&1 ? 1 : -1;

    std::vector<ll> vs;

    rep( i, N )
      vs.emplace_back( s1*x[i]+s2*y[i]+s3*z[i] );

    std::sort( all(vs) );

    ll sum = 0;
    for( int i = N-1; i >= N-M; --i )
      sum += vs[i];

    chmax( ans, sum );
  }

  printf( "%lld\n", ans );

  return 0;
}