#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
#include <stack>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;
using P = std::pair<ll, ll>;

ll N, M;
std::vector<ll> G[100010], ord;
ll deg[100010], dep[100010], ans[100010];

int main()
{
  std::cin >> N >> M;

  rep( i, N-1+M )
  {
    ll A, B;
    std::cin >> A >> B;

    --A; --B;

    G[A].emplace_back( B );
    ++deg[B];
  }

  std::stack<int> st;

  rep( i, N ) if( !deg[i] )
    st.push( i );

  while( !st.empty() )
  {
    ll v = st.top(); st.pop();

    ord.emplace_back( v );

    for( auto &u : G[v] )
    {
      --deg[u];

      if( !deg[u] )
        st.push( u );
    }
  }

  for( auto i : ord ) for( auto j : G[i] )
    chmax( dep[j], dep[i]+1 );

  ll root = ord[0];
  ans[root] = -1;

  rep( i, N ) for( auto j : G[i] ) if( dep[i]+1 == dep[j] )
    ans[j] = i;

  rep( i, N )
    std::cout << ans[i]+1 << std::endl;

  return 0;
}