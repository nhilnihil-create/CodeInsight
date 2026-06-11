/*
 * atcoder/abc092/c.cpp
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

const int MAX = 100100;
int N;
vector<int> A;
ll acc_l[MAX] = {0}, acc_r[MAX] = {0};
void solve() {
  cin >> N;
  int a;
  A.push_back(0);
  loop(n,0,N) {
    cin >> a;
    A.push_back(a);
  }
  A.push_back(0);
  N += 2;

  loop(n,1,N) {
    acc_l[n] = acc_l[n-1] + abs(A[n] - A[n-1]);
  }
  for (int n=N-1; n>=1; n--) acc_r[n-1] = acc_r[n] + abs(A[n] - A[n-1]);
  // loop(n,0,N) cout << acc_l[n] << " "; cout << endl;
  // loop(n,0,N) cout << acc_r[n] << " "; cout << endl;

  loop(k,1,N-1) {
    cout << acc_l[k-1] + abs(A[k+1]-A[k-1]) + acc_r[k+1] << endl;
  }
}
int main() {
  // cout.precision(15); cout << fixed;

  solve();

  return 0;
}
