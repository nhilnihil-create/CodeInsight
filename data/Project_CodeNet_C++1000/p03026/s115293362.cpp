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

ll N;
std::vector<ll> G[10010];
ll c[10010];
ll deg[10010];
ll ans[10010];

int main()
{
  std::cin >> N;

  rep( i, N-1 ) {
    ll a, b;
    std::cin >> a >> b;
    --a; --b;

    G[a].emplace_back( b );
    G[b].emplace_back( a );

    ++deg[a];
    ++deg[b];
  }

  rep( i, N )
    std::cin >> c[i];

  std::sort( c, c+N );

  std::priority_queue<P, std::vector<P>, std::greater<P>> pque;

  rep( i, N )
    pque.emplace( deg[i], i );

  ll score = 0;
  ll ptr = 0;

  while( !pque.empty() ) {
    P p = pque.top(); pque.pop();

    if( p.first > deg[p.second] || ans[p.second] )
      continue;

    if( ptr >= N )
      break;

    ll v = p.second;

    ans[v] = c[ptr];
    score += deg[v]*c[ptr];

    ++ptr;

    for( auto u : G[v] )
    {
      --deg[u];

      pque.emplace( deg[u], u );
    }
  }

  std::cout << score << std::endl;

  rep( i, N )
    std::cout << ans[i] << (i==N-1?'\n':' ');

  return 0;
}