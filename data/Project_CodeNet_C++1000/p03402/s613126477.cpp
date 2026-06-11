#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  char grid[100][100];
  rep(i, 100) {
    rep(j, 100)
      grid[i][j] = (i < 50 ? '#' : '.');
  }
  int a, b;
  cin >> a >> b;
  a--, b--;
  for (int i = 0; a && i < 50; i += 2) {
    for (int j = 0; a && j < 100; a--, j += 2)
      grid[i][j] = '.';
  }
  for (int i = 51; b && i < 100; i += 2) {
    for (int j = 0; b && j < 100; b--, j += 2)
      grid[i][j] = '#';
  }
  cout << "100 100\n";
  rep(i, 100) {
    rep(j, 100)
      cout << grid[i][j];
    cout << endl;
  }
  return 0;
}