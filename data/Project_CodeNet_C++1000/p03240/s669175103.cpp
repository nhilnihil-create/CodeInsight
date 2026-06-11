/*
 * atcoder/abc112_2nd/c.cpp
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

template <class T>
bool allEqual(vector<T> &vec) {
  return adjacent_find(vec.begin(), vec.end(), not_equal_to<>()) == vec.end();
}

int N;
vector<ll> X, Y, H;

void solve() {
  cin >> N;
  ll x, y, h;
  loop(n,0,N) {
    cin >> x >> y >> h;
    if (h > 0) X.push_back(x), Y.push_back(y), H.push_back(h);
  }
  N = H.size();
  if (N == 1) {
    cout << X[0] << " " << Y[0] << " " << H[0] << endl;
    return;
  }

  loop(cx,0,101) loop(cy,0,101) {
    vector<ll> vec;
    loop(n,0,N) vec.push_back(H[n] + abs(cx - X[n]) + abs(cy - Y[n]));
    if (allEqual<ll>(vec)) {
      cout << cx << " " << cy << " " << vec[0] << endl;
      return;
    }
  }
}
int main() {
  // cout.precision(15);
  // cout << fixed << double

  solve();

  return 0;
}
