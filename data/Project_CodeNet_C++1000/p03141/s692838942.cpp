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
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;
const ll INF = 1ll<<60;

ll N;
ll A[100010], B[100010];
std::vector<ll> vs;
ll ans;

int main()
{
  std::cin >> N;

  rep( i, N )
    std::cin >> A[i] >> B[i], ans -= B[i], vs.emplace_back( A[i]+B[i] );

  std::sort( vs.rbegin(), vs.rend() );

  for( ll i = 0; i < N; i += 2 )
    ans += vs[i];

  std::cout << ans << std::endl;

  return 0;
}