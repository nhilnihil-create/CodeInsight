
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

#define rep(i,n)  for(int i = 0; i < (int)(n);    i++)
#define sz(x)     ((int)(x).size())
#define all(x)    (x).begin(),(x).end()

using ll = long long;

ll gcd ( ll a, ll b ) { if ( b == 0 ) return a; else return gcd ( b, a%b ); }
ll lcm ( ll a, ll b ) { return a * b / gcd(a, b); }

int main (void) {
  std::cin.tie(0);  std::ios::sync_with_stdio(false);
  ll M, K; std::cin >> M >> K;
  if ( M == 0 ) {
    if ( K != 0 ) std::cout << -1 << std::endl;
    else std::cout << "0 0" << std::endl;
    return 0;
  }
  else if ( M == 1 ) {
    if ( K != 0 ) std::cout << -1 << std::endl;
    else std::cout << "0 0 1 1" << std::endl;
    return 0;
  }
  else {
    ll nmax = std::pow(2LL,M);  nmax--;
    if ( K > nmax ) std::cout << -1 << std::endl;
    else {
      rep(i,nmax+1) if ( (nmax-i) != K ) std::cout << nmax-i << " ";
      std::cout << K << " ";
      rep(i,nmax+1) if ( i != K ) std::cout << i << " ";
      std::cout << K << std::endl;
    }
  }
  return 0;
}

