#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int M;
  ll K;
  cin >> M >> K;
  if (M == 1) {
    if (K == 0) {
      cout << "0 0 1 1" << endl;
    } else {
      cout << -1 << endl;
    }
    return 0;
  }

  
  if (0 <= K && K < (1 << M)) {
    cout << K << " ";
    for (int i = (1 << M) - 1; i >= 0; i--) {
      if (i == K) {
        continue;
      }
      cout << i << " ";
    }
    cout << K << " ";
    for (int i = 0; i <= (1 << M) - 1; i++) {
      if (i == K) {
        continue;
      }
      cout << i << " ";
    }
  } else {
    cout << -1 << endl;
  }
  return 0;
}