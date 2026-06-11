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
ll a[200010], b[200010];
std::vector<ll> G[200010];

/*std::vector<ll> next( const std::vector<ll> &st, ll v )
{
  std::vector<ll> ret = st;

  ret[v] = 0;

  bool used[200010];

  rep( i, N+1 )
    used[i] = false;

  std::queue<P> que;
  que.emplace( v, -1 );

  while( !que.empty() )
  {
    P p = que.front(); que.pop();

    used[p.first] = true;

    if( p.first != v )
    {
      ret[p.second] += ret[p.first];
      ret[p.first] = 0;
    }

    for( auto u : G[p.first] ) if( !used[u] )
    {
      que.emplace( u, p.first );
    }
  }

  return ret;
}

ll grundy( const std::vector<ll> &st )
{
  bool fl = true;

  rep( i, N )
    fl &= st[i]==0;

  if( fl )
    return 0;

  std::set<ll> S;

  std::cout << st << std::endl;

  rep( i, N ) if( st[i] )
    S.emplace( grundy( next( st, i ) ) );

  rep( i, N ) if( !S.count(i) )
    return i;

  return N;
}*/

ll subtree[200010];
ll bit[200010];
ll sv;

ll bfs( ll v )
{
  std::queue<P> que;
  que.emplace( v, 0 );

  bool used[200010];

  rep( i, N+1 )
    used[i] = false;

  ll ret = 0;

  while( !que.empty() )
  {
    P p = que.front(); que.pop();
    ll u = p.first, dist = p.second;

    used[u] = true;

    bool upd = false;

    //std::cout << p << std::endl;

    for( auto ver : G[u] ) 
    {
      //std::cout << ver << ' ' << used[ver] << std::endl;

      if( used[ver] )
        continue;

      que.emplace( ver, dist+1 );

      upd = true;
    }

    if( !upd )
    {
      if( ret < dist )
      {
        sv = u;
        ret = dist;
      }
    }
  }

  return ret;
}

int main()
{
  std::cin >> N;

  rep( i, N-1 )
  {
    std::cin >> a[i] >> b[i];
    --a[i], --b[i];

    G[a[i]].emplace_back( b[i] );
    G[b[i]].emplace_back( a[i] );
  }

  bfs( 0 );

  ll L = bfs(sv);

  puts( L%3==1 ? "Second" : "First" );

  return 0;
}