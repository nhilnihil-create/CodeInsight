/*
 * atcoder/abc101/c.cpp
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
 * 最小値とインデックスnを求める.
 * その最小値nを含めるようにKを選択.
 * (K-1)/N-n + (K-1)/n
 *
 * 問題は、K=2より大きい時に最初のKのとり方が複数あること
 * 全部試してもO(K)なので全探索
 */
int N, K;
vector<int> A;

void solve() {
  cin >> N >> K;
  int a;
  int min_ = 200000, idx = -1;
  loop(n,0,N) {
    cin >> a;
    A.push_back(a);
    if (chmin(min_, a)) idx = n;
  }

  min_ = 200000;
  for (int k=max(0, idx-K+1); k<=idx; k++) {
    int cost = 1, cost_l = 0, cost_r = 0;
    int left = k-1, right = k+K;
    if (left>=0) cost_l = (int)ceil((left+1)/(double)(K-1));
    if (right<=N) cost_r = (int)ceil((N-right)/(double)(K-1));
    chmin(min_, cost_l + cost + cost_r);
    // cout << "k=" << k << " : " << cost_l << " " << cost << " " << cost_r << endl;
  }
  cout << endl << min_ << endl;
}
int main() {
  // cout.precision(15);
  // cout << fixed << double

  solve();

  return 0;
}
