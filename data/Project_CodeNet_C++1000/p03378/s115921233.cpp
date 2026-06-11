#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int N, M, X;
  cin >> N >> M >> X;
  vector<int> A(M);
  rep(i, M) {
    cin >> A[i];
  }

  // 0へ向かう
  int to0 = 0;
  int toN = 0;
  rep(i, M) {
    if (A[i] < X) {
      to0++;
    } else {
      toN++;
    }
  }

  cout << min(to0, toN) << endl;
  
  return 0;
}