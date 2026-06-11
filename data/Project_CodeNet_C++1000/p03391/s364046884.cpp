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
ll A[200010], B[200010];
ll S, mi = 1ll<<60;
bool fl = true;

int main()
{
  std::cin >> N;

  rep( i, N )
  {
    std::cin >> A[i] >> B[i];

    S += A[i];

    if( A[i] > B[i] )
      chmin( mi, B[i] );

    fl &= A[i]==B[i];
  }

  std::cout << (fl ? 0 : S-mi) << std::endl;

  return 0;
}