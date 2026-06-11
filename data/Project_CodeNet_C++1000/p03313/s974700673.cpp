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
#define endl '\n'
#define debug(x) std::cerr << #x << " = " << (x) << endl;

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

constexpr ll BIT_SIZE = (1ll<<18)+10;

ll N;
ll A[BIT_SIZE];
ll dp[BIT_SIZE], dp2[BIT_SIZE];

int main() {
  std::cin >> N;

  rep( i, 1ll<<N )
    std::cin >> A[i], dp[i] = A[i];

  rep( j, N ) rep( i, 1ll<<N ) if( i>>j&1 ) {
    ll pi = i & ~(1<<j);
    if( dp[i] < dp[pi] ) {
      dp2[i] = dp[i];
      dp[i] = dp[pi];
    } else if( dp2[i] < dp[pi] ) {
      dp2[i] = dp[pi];
    }
  }

  ll ans = 0;

  repi( k, 1, 1ll<<N ) {
    chmax( ans, dp[k]+dp2[k] );

    std::cout << ans << endl;
  }

  return 0;
}