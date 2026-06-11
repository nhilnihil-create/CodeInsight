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
ll D[60];
ll ans = 0;
ll used[30];
std::map<ll, ll> mp;
std::vector<ll> vs;

ll diff()
{
  ll ret = 30;

  rep( i, 25 ) rep( j, 25 ) if( used[i] && used[j] && i != j )
  {
    ll d1 = llabs(i-j);
    ll d2 = 24-d1;

    chmin( ret, std::min( d1, d2 ) );
  }

  return ret;
}

int main()
{
  std::cin >> N;

  rep( i, N )
    std::cin >> D[i], ++mp[D[i]];

  if( mp[0] )
  {
    puts("0");

    return 0;
  }

  used[0] = true;

  repi( i, 1, 12 )
  {
    if( mp[i] == 1 )
      vs.emplace_back( i );
    else if( mp[i] == 2 )
      used[i] = used[24-i] = true;
    else if( mp[i] > 2 )
    {
      puts("0");
      
      return 0;
    }
  }

  if( mp[12] == 1 )
    used[12] = true;
  else if ( mp[12] >= 2 )
  {
    puts("0");

    return 0;
  }

  ll M = vs.size();

  if( !M )
  {
    std::cout << diff() << std::endl;

    return 0;
  }

  rep( bit, 1<<M )
  {
    rep( i, M )
    {
      if( bit>>i&1 )
      {
        used[vs[i]] = true;
        used[24-vs[i]] = false;
      }
      else
      {
        used[vs[i]] = false;
        used[24-vs[i]] = true;
      }
    }

    ans = std::max( ans, diff() );
  }

  std::cout << ans << std::endl;

  return 0;
}