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
#define repi(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;

ll N;

int main()
{
  scanf( "%lld", &N );

  repi( h, 1, 3501 ) repi( n, 1, 3501 )
  {
    ll c = 4*h*n-N*n-N*h;
    ll r = N*h*n;

    if( c && r && r*c > 0 && r % c == 0 )
    {
      ll w = r/c;

      printf( "%lld %lld %lld\n", h, n, w );

      return 0;
    }
  }

  return 0;
}