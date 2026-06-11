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

ll N, K;
ll V[100];
ll ans;

int main()
{
  std::cin >> N >> K;

  rep( i, N )
    std::cin >> V[i];

  rep( l, N+1 ) rep( r, N+1 )
  {
    if( l+r > N )
      continue;

    if( l+r > K )
      continue;

    ll rest = K-(l+r);

    std::vector<ll> vs;

    rep( i, l )
      vs.emplace_back( V[i] );
    for( ll i = N-1; i >= N-r; --i )
      vs.emplace_back( V[i] );

    std::sort( rall(vs) );

    rep( i, rest ) if( !vs.empty() && vs.back() < 0 )
      vs.pop_back();

    ll sum = 0;
    rep( i, vs.size() )
      sum += vs[i];

    chmax( ans, sum );
  }

  std::cout << ans << std::endl;

  return 0;
}