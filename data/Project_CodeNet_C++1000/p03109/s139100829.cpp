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

string S;

void input() {
  cin >> S;
}

void solve() {
  // 0123456789
  // yyyy/mm/dd
  int m = stoi(S.substr(5, 2));
  int d = stoi(S.substr(8, 2));
  if (m <= 4) {
    cout << "Heisei" << endl;
    return;
  }

  cout << "TBD" << endl;
}

int main() {
  // cout.precision(15);
  input();
  solve();
  return 0;
}
