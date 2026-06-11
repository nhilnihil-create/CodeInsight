/*
 * atcoder/abc102_2nd/c.cpp
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
 * f(b) = |A_1 - 1 - b| + |A_2 - 2 - b| + ... + |A_N - N - b|
 * f(b)の最小値を求めよ. bは任意の整数.
 *
 * 全項で-bは共通だな。(A_i - i) だけ異なる.
 * 直感的には、A_i - i の中央値をbにすれば最小化するだろうか.
 * 証明が必要だ.
 */
int N;
vector<ll> A, B;
void solve() {
  cin >> N;
  ll a;
  loop(n,0,N) {
    cin >> a;
    A.push_back(a); B.push_back(a - (n + 1));
  }
  sort(B.begin(), B.end());
  ll b = B[B.size()/2];
  ll total = 0;
  loop(n,0,N) {
    total += abs(A[n] - (n+1) - b);
  }
  cout << total << endl;
}
int main() {
  // cout.precision(15); cout << fixed;

  solve();

  return 0;
}
