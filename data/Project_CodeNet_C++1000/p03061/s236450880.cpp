/*
g++ --std=c++17 A.cpp
*/

#include <iostream>
#include <iomanip> //! for setprecision(20)
#include <math.h>
#include <algorithm>
#include <functional> 
#include <string>
#include <vector>

#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <limits.h>

using namespace std;

typedef long long LL;

#define rep(i,n) for (int i = 0; i < int(n); ++i)
template<class T> inline bool chmax(T& a, T b) { bool ret = (a < b); if (ret) { a = b; } return ret; }
template<class T> inline bool chmin(T& a, T b) { bool ret = (b < a); if (ret) { a = b; } return ret; }
#define dump(c) { for (auto it = c.begin(); it != c.end(); ++it) if (it == c.begin()) cout << *it; else cout << ' ' << *it; cout << endl; } 
#define dumpMap(m) { for (auto it: m) cout << it.first << "=>" << it.second << ' '; }

const int INF = 1e9;
const LL INFL = 1e18;
const int MOD = 1000000007;


template<typename T>
T gcd(T a, T b) 
{
    if (b < a) { //! make sure a <= b
        T tmp = b;
        b = a;
        a = tmp;
    }

    T r = b % a;
    while (r) {
        b = a;
        a = r;
        r = b % a;
    }

    return a;
}


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> lg(n), rg(n);
  for (int i = 1; i <= n-1; ++i) {
    if (i == 1) {
      lg[1] = a[0];
      rg[1] = a[n-1];
    } else {
      lg[i] = gcd(lg[i-1], a[i-1]);
      rg[i] = gcd(rg[i-1], a[n-i]);
    }
  }
 
  // cout << "lg" << endl; dump(lg); cout << endl;
  // cout << "rg" << endl; dump(rg); cout << endl;

  int ans = max(lg[n-1], rg[n-1]);
  for (int l = 1; l <= n-2; ++l) {
    int r = n-l-1;
    int tmp = gcd(lg[l], rg[r]);
    // cout << "  l = " << l << ", r = " << r << ", tmp = " << tmp << endl;
    ans = max(ans, tmp);
  }

  cout << ans << endl;

  return 0;
}