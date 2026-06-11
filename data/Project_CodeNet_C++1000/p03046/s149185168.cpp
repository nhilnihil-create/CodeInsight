#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int M, K;
  cin >> M >> K;
  if ((1 << M) <= K) {
    cout << -1 << endl;
  } else if (M == 0) {
    cout << "0 0" << endl;
  } else if (M == 1) {
    if (K == 0) {
      cout << "0 0 1 1" << endl;
    } else {
      cout << -1 << endl;
    }
  } else {
    rep(i, 1 << M) {
      if (i != K) cout << i << " ";
    }
    cout << K << " ";
    for (int i = (1 << M) - 1; i >= 0; --i) {
      if (i != K) cout << i << " ";
    }
    cout << K << endl;
  }
  return 0;
}