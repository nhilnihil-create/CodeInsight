
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <cmath>
#include <string>
#include <queue>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <iomanip> // std::std::setprecision(X)
#include <limits>  //std::numeric_limits<int>::max(), min()

typedef long long ll;

namespace MyMod {
  typedef long long ll;
  constexpr ll mod = 1e9+7;
  constexpr ll premax = 200020; std::array<ll, premax> f, rf; bool flag = false;

  ll power (ll e, ll x){
    if (x == 0) return 1LL; if (x % 2 != 0) return ((power(e, x-1) * e) % mod);
    ll temp = power(e, x / 2); return (temp * temp) % mod;
  }
  ll add ( ll a, ll b ) { return ((a%mod) + (b%mod))%mod; }
  ll sub ( ll a, ll b ) { return ( a%mod + mod - b%mod)%mod; }
  ll mul ( ll a, ll b ) { return ((a%mod) * (b%mod)) % mod; }
  ll div ( ll a, ll b ) { return ((a%mod) * power(b,mod-2)) % mod; }
  ll nCk (int n, int k) {
    if ( !flag ) {
      f[0] = 1; for(int i=1; i<premax; i++) f[i] = mul(f[i - 1],i);
      rf[premax-1] = power(f[premax-1], mod-2); for(int i=premax-2; i>=0; i--) rf[i] = mul(rf[i + 1], (i + 1));
      flag = true;
    }
    return mul(f[n], mul(rf[n-k], rf[k]));
  }
  ll nPk (int n, int k) {
    if ( !flag ) {
      f[0] = 1; for(int i=1; i<premax; i++) f[i] = mul(f[i - 1],i);
      rf[premax-1] = power(f[premax-1], mod-2); for(int i=premax-2; i>=0; i--) rf[i] = mul(rf[i + 1], (i + 1));
      flag = true;
    }
    return mul(f[n], rf[n-k]);
  }
}

std::string S; 
std::vector<std::vector<int>> dp;

// i番目の文字までみたときの ...A...(0) or ... A...B...(1) or ...A...B...C...(2)の場合の数 と 総数(3)
ll sol(int i, int j) {
  if ( dp[i][j] != -1 ) return dp[i][j];

  if ( S[i-1] == 'A' ) {
    dp[i][3] = sol(i-1,3) ;
    dp[i][0] = MyMod::add(sol(i-1,0), sol(i-1, 3));
    dp[i][1] = sol(i-1,1) ;
    dp[i][2] = sol(i-1,2) ;
    return dp[i][j];
  }
  if ( S[i-1] == 'B' ) {
    dp[i][3] = sol(i-1,3) ;
    dp[i][0] = sol(i-1,0) ;
    dp[i][1] = MyMod::add(sol(i-1,1), sol(i-1,0) );
    dp[i][2] = sol(i-1,2) ;
    return dp[i][j];
  }
  if ( S[i-1] == 'C' ) {
    dp[i][3] = sol(i-1,3) ;
    dp[i][0] = sol(i-1,0) ;
    dp[i][1] = sol(i-1,1) ;
    dp[i][2] = MyMod::add( sol(i-1,2), sol(i-1,1) );
    return dp[i][j];
  }
  if ( S[i-1] == '?' ) {
    // A case
    dp[i][3] = sol(i-1,3) ;
    dp[i][0] = MyMod::add(sol(i-1,0), sol(i-1, 3));
    dp[i][1] = sol(i-1,1) ;
    dp[i][2] = sol(i-1,2) ;
    // B case
    dp[i][3] += sol(i-1,3) ;
    dp[i][0] += sol(i-1,0) ;
    dp[i][1] += MyMod::add(sol(i-1,1), sol(i-1,0) );
    dp[i][2] += sol(i-1,2) ;
    for(int j=0; j<4; j++) dp[i][j] %= MyMod::mod;
    // C case
    dp[i][3] += sol(i-1,3) ;
    dp[i][0] += sol(i-1,0) ;
    dp[i][1] += sol(i-1,1) ;
    dp[i][2] += MyMod::add( sol(i-1,2), sol(i-1,1) );
    for(int j=0; j<4; j++) dp[i][j] %= MyMod::mod;
    return dp[i][j];
  }
}


int main (void) {

  std::cin >> S;
  dp.resize(S.size()+1); for(int i=0; i<S.size()+1; i++) dp[i].assign(4,-1);

  dp[0][0] = 0;
  dp[0][1] = 0;
  dp[0][2] = 0;
  dp[0][3] = 1;

  std::cout << sol(S.size(), 2) << std::endl; 

  /*
  std::cout << "************" << std::endl;
  for(int i=0; i<=S.size(); i++) {
    for(int j=0; j<4; j++) std::cout << dp[i][j] << " ";
    std::cout << std::endl;
  }
  */
  return 0;
}
