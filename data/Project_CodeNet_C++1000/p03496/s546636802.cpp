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
  int n;
  cin >> n;
  vector<int> a(n);
  int idx = 0;
  rep(i, n) {
    cin >> a[i];
    if (abs(a[i]) > abs(a[idx]))
      idx = i;
  }
  if (a[idx] > 0) {
    cout << (n-1)*2 << endl;
    cout << idx+1 << ' ' << 2 << endl;
    cout << idx+1 << ' ' << 2 << endl;
    for (int i = 2; i < n; i++) {
      cout << i << ' ' << i+1 << endl;
      cout << i << ' ' << i+1 << endl;
    }
  } else if (a[idx] < 0) {
    cout << (n-1)*2 << endl;
    cout << idx+1 << ' ' << n-1 << endl;
    cout << idx+1 << ' ' << n-1 << endl;
    for (int i = n-1; i > 1; i--) {
      cout << i << ' ' << i-1 << endl;
      cout << i << ' ' << i-1 << endl;
    }
  } else
    cout << 0 << endl;
  return 0;
}