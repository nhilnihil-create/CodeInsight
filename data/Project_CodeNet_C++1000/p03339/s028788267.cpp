/*
 * atcoder/abc98/c.cpp
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

const int MAX = 300100;
int N;
string S;
int acc_e[MAX] = {0}, acc_w[MAX] = {0};

void solve() {
  cin >> N >> S;
  for (int n=0; n<N; n++) acc_e[n+1] = acc_e[n] + (S[n] == 'E');
  for (int n=0; n<N; n++) acc_w[n+1] = acc_w[n] + (S[n] == 'W');
  int min_ = 400000;
  loop(n,0,N) chmin(min_, acc_w[n] + (acc_e[N] - acc_e[n+1]));
  cout << min_ << endl;
}
int main() {
  // cout.precision(15); cout << fixed;

  solve();

  return 0;
}
