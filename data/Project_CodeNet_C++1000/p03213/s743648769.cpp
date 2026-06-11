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

bool used[1000010];
std::vector<ll> primes;

void sieve( ll n ) {
  used[0] = used[1] = true;

  for( ll i = 2; i*i <= n; ++i ) {
    if( used[i] )
      continue;

    primes.emplace_back( i );

    for( ll j = i; j <= n; j += i )
      used[j] = true;
  }

  return;
}

ll N;

int main()
{
  std::cin >> N;

  sieve( 1000010 );

  ll cnt2 = 0, cnt4 = 0, cnt14 = 0, cnt24 = 0, cnt74 = 0;

  for( auto p : primes ) {
    ll n = N, e = 0;
    
    while( n > 0 ) {
      e += n/p;
      n /= p;
    }

    if( e >= 74 ) {
      ++cnt74;
    }
    if( e >= 24 ) {
      ++cnt24;
    }
    if( e >= 14 ) {
      ++cnt14;
    }
    if( e >= 4 ) {
      ++cnt4;
    }
    if( e >= 2 ) {
      ++cnt2;
    }
  }

  auto comb = [&]( ll cS, ll cL ) {
    return (cS-cL)*cL*(cL-1)/2+cL*(cL-1)*(cL-2)/2;
  };

  auto count = [&]( ll cS, ll cL ) {
    return (cS-cL)*cL+cL*(cL-1);
  };

  ll ans = comb( cnt2, cnt4 );
  ans += count( cnt4, cnt14 );
  ans += count( cnt2, cnt24 );
  ans += cnt74;

  std::cout << ans << std::endl;

  return 0;
}