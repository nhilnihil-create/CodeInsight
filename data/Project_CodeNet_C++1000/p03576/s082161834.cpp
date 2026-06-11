
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


int main (void) {
  std::cin.tie(0);  std::ios::sync_with_stdio(false);
  int N, K; std::cin >> N >> K;

  std::vector<ll> x(N), y(N);
  rep(i,N) std::cin >> x[i] >> y[i];

  // O(N^4) x O(N)
  ll ans = (1LL<<62);
  for(int a=0;   a<N; a++) 
  for(int b=a+1; b<N; b++)
  for(int c=0;   c<N; c++) 
  for(int d=c+1; d<N; d++) {
    ll xup = std::max( { x[a], x[b] } );
    ll xdn = std::min( { x[a], x[b] } );
    ll yup = std::max( { y[c], y[d] } );
    ll ydn = std::min( { y[c], y[d] } );
    int tmp = 0;
    rep(i,N) if ( xdn <= x[i] && x[i] <= xup && ydn <= y[i] && y[i] <= yup ) tmp++;
    if ( tmp >= K ) ans = std::min(ans, std::abs(xup-xdn)*std::abs(yup-ydn) );
  }
  std::cout << ans << std::endl;
  return 0;
}
