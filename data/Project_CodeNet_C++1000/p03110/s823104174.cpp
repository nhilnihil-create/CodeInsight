/*
 * atcoder/abc130/a.cpp
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

int N;
double X[10];
string U[10];

void input() {
  cin >> N;
  loop(n,0,N) cin >> X[n] >> U[n];
}

void solve() {
  double total = 0.0;
  loop(n,0,N) {
    if (U[n] == "BTC") {
      total += X[n] * 380000.0;
    } else {
      total += X[n];
    }
  }
  cout << total << endl;
}

int main() {
  // cout.precision(15);
  input();
  solve();
  return 0;
}
