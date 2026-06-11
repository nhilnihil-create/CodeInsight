
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <cmath>
#include <string>
#include <sstream>
#include <queue> 
#include <list>
#include <stack>
#include <unordered_map>
#include <algorithm> 
#include <numeric>  
#include <functional>
#include <cassert>
#include <bitset>
#include <cctype>  
#include <iomanip> 
#include <limits>  
#include <regex>
// std::numeric_limits<int>::max(), min()
// std::setprecision(X)
// std::islower(), std::isupper(), std::tolower, std::toupper
// std::accumulate(m.begin(), m.end(), 0LL);
// std::sort(begin(),end()) // 0, 1, 2, 3 ,4 (default, less);
// std::priority_queue<int, vector<int>, less<int>> que; // 4, 3, 2, 1 (defualt, less) : 
// if ( std::regex_match(S, std::regex("(dream|dreamer|erase|eraser)*")) ) std::cout << "YES" << std::endl;
 
#define rep(i, n) for(int i = 0; i < (int)(n);    i++)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;

ll gcd ( ll a, ll b ) { if ( b == 0 ) return a; else return gcd ( b, a%b ); }
ll lcm ( ll a, ll b ) { return a * b / gcd(a, b); }

int N; 
ll Z, W; 
std::vector<ll> a;
std::vector<ll> dp[2];

// maenohito < k made hiita
ll sol(int k, int z, int w, bool isX) {
  if ( k >= N ) return std::abs(z-w);
  if ( dp[isX][k] != -1e11 ) return dp[isX][k];

  ll has = 0;
  if ( isX ) {
    has = -1e10;
    for(int i=k; i<N; i++) chmax(has, sol(i+1, a[i], w, !isX));
  }
  else {
    has =  1e10;
    for(int i=k; i<N; i++) chmin(has, sol(i+1, z, a[i], !isX));
  }
  return dp[isX][k] = has;
}

int main (void) {
  std::cin.tie(0);  std::ios::sync_with_stdio(false);
  std::cin >> N;  a.resize(N); dp[0].resize(N+1, -1e11); dp[1].resize(N+1, -1e11);
  std::cin >> Z >> W;
  rep(i,N) std::cin >> a[i];

  std::cout << sol(0, Z, W, true) << std::endl;
  
  return 0;
}
