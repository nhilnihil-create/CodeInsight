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
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  cout << 0 << endl << flush;
  string s0;
  cin >> s0;
  if (s0 == "Vacant") return 0;
  int l = 1, r = n;
  while (true) {
    int mid = (l+r)/2;
    cout << mid << endl << flush;
    string s;
    cin >> s;
    if (s == "Vacant") return 0;
    if (mid%2 && s != s0 || !(mid%2) && s == s0)
      l = mid+1;
    else
      r = mid;
  }
  return 0;
}