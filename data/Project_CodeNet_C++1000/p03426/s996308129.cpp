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
using P = std::pair<ll, ll>;

ll H, W, D;
ll A[310][310];
ll Q;

std::map<ll, P> mp;
std::vector<std::vector<ll>> S;

int main()
{
  std::cin >> H >> W >> D;

  rep( i, H ) rep( j, W )
  {
    std::cin >> A[i][j];

    mp[A[i][j]] = P( i, j );
  }

  rep( d, D )
  {
    ll prv = 0;

    S.emplace_back( std::vector<ll>( 1, 0 ) );

    rep( x, (H*W-d+D-1)/D+2 ) if( x > 0 )
    {
      P np = mp[d+x*D];
      P pp = mp[d+(x-1)*D];

      prv += llabs(np.first-pp.first)+llabs(np.second-pp.second);

      S[d].emplace_back( prv );
    }
  }

  std::cin >> Q;
  
  rep( q, Q )
  {
    ll L, R;
    std::cin >> L >> R;

    ll d = L%D;
    ll x1 = (L-d)/D;
    ll x2 = (R-L)/D;
    
    std::cout << S[d][x2+x1]-S[d][x1] << std::endl;
  }

  return 0;
}