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
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  int N, H, W;
  cin >> N >> H >> W;
  vector<int> A(N), B(N);
  rep(i, N) cin >> A[i] >> B[i];
  int ans = 0;
  rep(i, N) {
    if (A[i] >= H && B[i] >= W)
      ans++;
  }
  cout << ans << endl;
  return 0;
}