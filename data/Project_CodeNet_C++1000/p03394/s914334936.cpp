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

const ll arr[] = { 2, 5, 63, 20, 30 };

ll N;
std::set<ll> vs;
ll sum;

int main()
{
  std::cin >> N;

  if( N <= 5 )
  {
    rep( i, N )
      std::cout << arr[i] << (i==N-1?'\n':' ');

    return 0;
  }

  ll k = 0;
  
  while( vs.size() < N )
  {
    rep( i, 7 ) if( i && i != 1 && i != 5 )
    {
      vs.emplace( 6*k+i );

      sum += 6*k+i;

      if( i == 6 )
        ++k;

      if( vs.size() == N )
        goto end;
    }
  }
end:;

  if( sum % 6 == 2 )
  {
    vs.erase( vs.find(8) );


    repi( K, k-2, k+2 ) if( K >= 0 && 6*K > 0 && vs.find(6*K) == vs.end() )
    {
      vs.emplace( 6*K );
      
      break;
    }
  }
  else if( sum % 6 == 3 )
  {
    vs.erase( vs.find(9) );

    repi( K, k-2, k+2 ) if( K >= 0 && 6*K > 0 && vs.find(6*K) == vs.end() )
    {
      vs.emplace( 6*K );
      
      break;
    }
  }
  else if( sum % 6 == 5 )
  {
    vs.erase( vs.find(9) );

    repi( K, k-2, k+2 ) if( K >= 0 && 6*K+4 > 0 && vs.find(6*K+4) == vs.end() )
    {
      vs.emplace( 6*K+4 );
      
      break;
    }
  }

  itr( it, vs )
    std::cout << *it << (std::distance(it, vs.end())==1?'\n':' ');

  return 0;
}