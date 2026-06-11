/*
 * atcoder/abc097_2nd/c.cpp
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
int K, N;
void solve() {
  cin >> S >> K;
  N = S.size();
  vector<string> subs;
  for (int len=1; len<=K; len++) {
    for (int l=0; l+len<=N; l++) {
      subs.push_back(S.substr(l, len));
    }
  }
  sort(subs.begin(), subs.end());
  unique(subs.begin(), subs.end());
  cout << subs[K-1] << endl;
}
int main() {
  // cout.precision(15); cout << fixed;

  solve();

  return 0;
}
