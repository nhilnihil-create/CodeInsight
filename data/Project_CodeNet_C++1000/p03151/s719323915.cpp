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

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;

ll N;
ll A[100010], B[100010];
std::vector<ll> vs;
ll sum = 0, ans = 0;

int main()
{
  std::cin >> N;

  rep( i, N )
    std::cin >> A[i];

  rep( i, N )
    std::cin >> B[i];

  rep( i, N )
  {
    if( A[i] >= B[i] )
      vs.emplace_back( A[i]-B[i] );
  }

  std::sort( rall(vs) );

  rep( i, N )
  {
    if( A[i] < B[i] )
      sum += B[i]-A[i], ++ans;
  }

  bool fl = false;

  rep( i, vs.size() )
  {
    if( sum <= 0 )
    {
      fl = true;

      break;
    }

    sum -= vs[i];

    ++ans;
  }

  if( sum <= 0 )
    fl = true;

  std::cout << (fl?ans:-1) << std::endl;

  return 0;
}