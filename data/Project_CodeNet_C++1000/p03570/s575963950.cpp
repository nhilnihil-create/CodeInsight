#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
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
#include <tuple>
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

constexpr int INF = 1ll<<30;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class S, class T>
std::ostream& operator<< ( std::ostream& out, const std::pair<S,T>& a )
{ std::cout << '(' << a.first << ", " << a.second << ')'; return out; }

template<class T>
std::ostream &operator<< ( std::ostream& out, const std::vector<T>& a )
{ std::cout << '['; rep( i, a.size() ){ std::cout << a[i]; if( i != a.size()-1 ) std::cout << ", "; } std::cout << ']'; return out; }

std::string s;
int dp[200010];
int memo[1ll<<26];

ll rev( ll bit, ll b ) {
  return bit^(1ll<<b);
}

int main() {
  std::cin >> s;

  ll n = s.size();
  ll par = 0;

  rep( i, n+5 )
    dp[i] = INF;
  rep( i, 1ll<<26 )
    memo[i] = INF;

  dp[0] = 0;
  memo[0] = 0;

  rep( i, n ) {
    par = rev( par, s[i]-'a' );
    chmin( dp[i+1], memo[par]+1 );
    
    rep( c, 26 ) {
      par = rev( par, c );
      chmin( dp[i+1], memo[par]+1 );
      par = rev( par, c );
    }

    chmin( memo[par], dp[i+1] );
  }

  std::cout << dp[n] << endl;

  return 0;
}