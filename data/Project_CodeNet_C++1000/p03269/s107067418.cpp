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

using ll = long long;
using P = std::pair<ll, ll>;

constexpr ll INF = 1ll<<60;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class S, class T>
std::ostream& operator<< ( std::ostream& out, const std::pair<S,T>& a )
{ std::cout << '(' << a.first << ", " << a.second << ')'; return out; }

template<class T>
std::ostream &operator<< ( std::ostream& out, const std::vector<T>& a )
{ std::cout << '['; rep( i, a.size() ){ std::cout << a[i]; if( i != a.size()-1 ) std::cout << ", "; } std::cout << ']'; return out; }

ll L;
std::vector<std::pair<P, ll>> ps;

int main()
{
  std::cin >> L;

  /*if( L == 2 )
  {
    std::cout << "2 2" << std::endl;
    std::cout << "1 2 0" << std::endl;
    std::cout << "1 2 1" << std::endl;

    return 0;
  }*/

  ll t = L;
  ll b = 0;

  while( t > 0 )
  {
    t >>= 1;
    ++b;
  }

  rep( i, b-1 )
  {
    ps.emplace_back( P( i+1, i+2 ), 1<<(b-i-2) );
    ps.emplace_back( P( i+1, i+2 ), 0 );
  }
  
  repd( i, b-1 ) if( L>>i&1 )
  {
    ll cost = ((L^(1<<i))>>i)<<i;

    ps.emplace_back( P( 1, b-i ), cost );
  }

  std::cout << b << ' ' << ps.size() << std::endl;

  for( auto p : ps )
    std::cout << p.first.first << ' ' << p.first.second << ' ' << p.second << std::endl;

  return 0;
}