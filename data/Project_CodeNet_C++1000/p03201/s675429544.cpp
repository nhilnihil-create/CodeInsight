#include <cstdio>
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

ll N;
ll A[200010];
std::multiset<ll> ms;
ll ans;

int main()
{
  scanf( "%lld", &N );

  rep( i, N )
  {
    scanf( "%lld", A+i );  
    ms.insert( A[i] );
  }

  while( !ms.empty() )
  {
    ll a = *ms.rbegin();
    ms.erase( ms.find(a) );

    ll b;

    for( int i = 32; i >= 0; --i ) if( (1<<i)-a > 0 )
      b = (1<<i)-a;

    auto it = ms.find( b );
    
    if( it != ms.end() )
    {
      ++ans;
      ms.erase( it );
    }
  }

  printf( "%lld\n", ans );

  return 0;
}