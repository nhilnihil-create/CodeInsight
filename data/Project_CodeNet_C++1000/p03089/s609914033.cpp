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
#define repdi(i,a,b) for(ll i=(a)-1;i>=(b);--i)
#define repd(i,a) repdi(i,a,0)
#define itr(it,a) for( auto it = (a).begin(); it != (a).end(); ++it )
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;

ll N;
std::vector<ll> b( 110 ), S[110];
std::vector<ll> ans;

int main()
{
  std::cin >> N;

  rep( i, N )
    std::cin >> b[i], --b[i];

  rep( i, N )
  {
    repd( j, N ) if( b[j] == j )
    {
      ans.emplace_back( j+1 );
      b.erase( b.begin()+j );

      break;
    }

    if( ans.size() != i+1 )
    {
      std::cout << -1 << std::endl;

      return 0;
    }
  }

  repd( i, N )
    std::cout << ans[i] << std::endl;

  return 0;
}