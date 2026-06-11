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

ll N, K;
ll a[1010], sum[1010];
std::vector<bool> removed;
std::vector<ll> S;

int main()
{
  scanf( "%lld%lld", &N, &K );

  rep( i, N )
    scanf( "%lld", a+i );

  rep( i, N )
    sum[i+1] += sum[i]+a[i];

  rep( i, N ) rep( j, i+1 )
    S.emplace_back( sum[i+1]-sum[j] );

  removed.assign( S.size(), false );

  ll ans = 0;

  for( int b = 40; b >= 0; --b )
  {
    ll cnt = 0;

    rep( i, S.size() ) if( !removed[i] )
      cnt += S[i]>>b&1;

    if( cnt >= K )
    {
      ans += 1ll<<b;

      rep( i, S.size() ) if( !removed[i] && !(S[i]>>b&1) )
      { removed[i] = true; }
    }
  }

  printf( "%lld\n", ans );

  return 0;
}