#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int K;
  cin >> K;
  ll A[K];
  for (int i = 0; i < K; i++) cin >> A[i];
  ll mi = 2;
  ll ma = 2;
  if (A[K-1] != 2) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = K-1; i >= 1; i--) {
    ma = ((ma + A[i] - 1) / A[i-1]) * A[i-1];
    mi = ((mi + A[i-1] - 1) / A[i-1]) * A[i-1];
    if (mi > ma) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << mi << " " << ma + A[0]  - 1 << endl;
  return 0;
}