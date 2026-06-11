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

ll N;
std::string S0;
bool fl;

int main()
{
  std::cin >> N;

  std::cout << 0 << std::endl;
  std::cin >> S0;

  if( S0 == "Vacant" )
  {
    return 0;
  }
  else
  {
    fl = S0=="Male"; 
  }

  ll ng = 0, ok = N;

  while( ok-ng > 1 )
  {
    ll mid = (ng+ok)/2;

    std::cout << mid << std::endl;

    std::string S;
    std::cin >> S;

    if( S == "Vacant" )
    {
      return 0;
    }

    if( (S == "Male") == (fl^(mid&1)) )
      ng = mid;
    else
      ok = mid;
  }

  return 0;
}