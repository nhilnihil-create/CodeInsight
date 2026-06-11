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
#define repi(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define itr(it,a) for( auto it = (a).begin(); it != (a).end(); ++it )
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;
using P = std::pair<ll, ll>;

ll N, K;
ll t[100010], d[100010];
std::vector<ll> vs[100010];
std::vector<ll> ps[2];
ll S[2][100010];
bool used[100010];
ll ans;

int main()
{
  std::cin >> N >> K;

  rep( i, N )
  {
    std::cin >> t[i] >> d[i];
    --t[i];
    vs[t[i]].emplace_back( d[i] );
  }

  rep( i, N )
  {
    if( vs[i].empty() )
      continue;

    std::sort( all(vs[i]) );

    ps[1].emplace_back( vs[i].back() );

    rep( j, vs[i].size()-1 )
      ps[0].emplace_back( vs[i][j] );
  }

  rep( i, 2 )
  {
    std::sort( ps[i].rbegin(), ps[i].rend() );

    rep( j, ps[i].size() )
      S[i][j+1] = S[i][j]+ps[i][j];
  }

  repi( y, std::max( 0ll, ll(K-ps[0].size()) ), K+1 )
  {
    if( y > ps[1].size() || K-y < 0 )
      continue;

    chmax( ans, S[0][K-y]+S[1][y]+ll(y*y) );
  }

  std::cout << ans << std::endl;

  return 0;
}