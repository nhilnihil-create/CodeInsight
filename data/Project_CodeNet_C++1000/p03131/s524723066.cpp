#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;
using ll = long long;

int main() {
  int K, A, B;
  cin >> K >> A >> B;

  ll biscuits = 1, yen = 0;
  if (B - 1 <= A) {
    biscuits += K;
  } else {
    while (0 < K) {
      if (0 < yen) {
        biscuits += B, yen--;
      } else if (1 < K && A <= biscuits) {
        biscuits -= A, yen++;
      } else {
        biscuits++;
      }
      K--;
    }
  }

  cout << biscuits << endl;
  return 0;
}
