/*
 * atcoder/abc97/c.cpp
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
vector<string> subs;
int counter[200] = {0};

void solve() {
  cin >> S >> K;
  N = S.size();
  for (int len=1; len<=K; len++) {
    for (int l=0; l+len<=N; l++) {
      subs.push_back(S.substr(l, len));
    }
  }
  sort(subs.begin(), subs.end());
  string prev = " ";
  int k=0;
  int n=1;
  for (; n<subs.size(); n++) {
    if (subs[n-1] != subs[n]) {
      k++;
      if (k==K) break;
    }
  }
  cout << subs[n-1] << endl;
}
int main() {
  // cout.precision(15); cout << fixed;

  solve();

  return 0;
}
