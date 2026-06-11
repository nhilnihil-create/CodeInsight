#include <cstdio>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;

ll N;
std::string S;
ll Q;

int main()
{
  std::cin >> N >> S >> Q;

  rep( q, Q )
  {
    ll k;
    std::cin >> k;

    ll cntD = 0, cntM = 0, cntP = 0, ans = 0;

    rep( i, N )
    {
      if( S[i] == 'D' )
        ++cntD;
      if( S[i] == 'M' )
      {
        ++cntM;
        cntP += cntD;
      }
      if( i-k >= 0 )
      {
        if( S[i-k] == 'D' )
        {
          --cntD;
          cntP -= cntM;
        }
        if( S[i-k] == 'M' )
          --cntM;
      }

      if( S[i] == 'C' )
        ans += cntP;
    }

    printf( "%lld\n", ans );
  }

  return 0;
}