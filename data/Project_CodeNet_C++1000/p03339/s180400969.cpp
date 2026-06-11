/*
 * atcoder/abc098_2nd/c.cpp
 */

// C++ 14
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring> // memset
#include <cassert>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
template <class T> bool chmin(T &a, T b) { if (a > b) {a = b; return true; } return false; }
template <class T> bool chmax(T &a, T b) { if (a < b) {a = b; return true; } return false; }

/*
 * WEWEWEEEWWWE
 * 112233334444
 * 011223455556
 */
int N;
vector<int> E, W;
void solve() {
  cin >> N;
  char c;
  E.resize(N+1); W.resize(N+1);
  E[0] = W[0] = 0;
  loop(n,1,N+1) {
    cin >> c;
    E[n] = E[n-1] + (c == 'E');
    W[n] = W[n-1] + (c == 'W');
  }

  int min_ = 400000;
  loop(k,1,N+1) {
    chmin(min_, W[k-1] + E[N] - E[k]);
  }
  cout << min_ << endl;
}
int main() {
  // cout.precision(15); cout << fixed;

  solve();

  return 0;
}
