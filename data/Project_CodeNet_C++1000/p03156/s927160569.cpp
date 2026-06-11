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
ll A, B;
ll P[110];
ll cnt1, cnt2, cnt3;

int main()
{
  std::cin >> N >> A >> B;
  rep( i, N )
    std::cin >> P[i];

  rep( i, N )
  {
    if( P[i] <= A )
      ++cnt1;
    else if( P[i] <= B )
      ++cnt2;
    else
      ++cnt3;
  }

  std::cout << std::min( cnt1, std::min( cnt2, cnt3 )) << std::endl;

  return 0;
}