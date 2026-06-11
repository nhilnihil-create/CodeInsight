
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
  int N; std::cin >> N;
  std::vector<ll> a(N); rep(i,N) std::cin >> a[i];
  ll amax = *std::max_element( all(a) );
  ll amin = *std::min_element( all(a) );
  int amaxid = std::distance(a.begin(), std::max_element( all(a) ));
  int aminid = std::distance(a.begin(), std::min_element( all(a) ));

  std::vector<std::pair<int,int>> ans;
  if ( amax * amin >= 0 ) {
    if ( amax == std::abs(amax) && amin == std::abs(amin) ) {
      for(int i=0; i<N-1; i++) ans.push_back( {i+1, i+2} );
    }
    else {
      for(int i=N-2; i>=0; i--) ans.push_back( {i+2, i+1} );
    }
  }
  else {
    if ( std::abs(amax) >= std::abs(amin) ) {
      for(int i=0; i<N; i++) ans.push_back( {amaxid+1, i+1} );
      for(int i=0; i<N-1; i++) ans.push_back( {i+1, i+2} );
    }
    else {
      for(int i=0; i<N; i++) ans.push_back( {aminid+1, i+1} );
      for(int i=N-2; i>=0; i--) ans.push_back( {i+2, i+1} );
    }
  }
  
  std::cout << sz(ans) << std::endl;
  rep(i,sz(ans)) {
    std::cout << ans[i].first << " " << ans[i].second << std::endl;
//    a[ans[i].second-1] += a[ans[i].first-1];
  }

//  rep(i,N) std::cout << a[i] << " ";
//  std::cout << std::endl;

  return 0;
}
