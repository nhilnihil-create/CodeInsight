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

ll M, K;

int main()
{
  std::cin >> M >> K;

  if( K >= (1ll<<M) ) {
    puts("-1");

    return 0;
  }

  if( M == 1 ) {
    if( K == 1 ) {
      puts("-1");

      return 0;
    }

    puts("0 0 1 1");

    return 0;
  }

  std::vector<ll> vs;

  rep( i, 1<<M ) if( i != K )
    vs.emplace_back( i );
  
  vs.emplace_back( K );

  repd( i, (1<<M) ) if( i != K )
    vs.emplace_back( i );

  vs.emplace_back( K );

  rep( i, vs.size() )
    std::cout << vs[i] << (i==vs.size()-1?'\n':' ');

  return 0;
}