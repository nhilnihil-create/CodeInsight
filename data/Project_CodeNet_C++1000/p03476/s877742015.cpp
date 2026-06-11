#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
struct erato {
  vector<bool> hyou;
  int mx;
  void init() {
    hyou[1] = true;
    for (int i = 2; i <= mx; i++) {
      if (hyou[i] == false) continue;
      hyou[i] = true;
      for (int j = 2; j <= mx / i; j++) {
        hyou[i * j] = false;
      }
    }
  }
  erato(int x) {
    hyou.resize(x + 3, true);
    mx = x;
    init();
  }
};
const int mx = 1e5;
int main() {
  int Q;
  cin >> Q;
  erato era(mx);
  vector<ll> A(mx + 1);
  A[0] = 0;
  for (int i = 1; i <= mx; i++) {
    A[i] = A[i - 1];
    if (era.hyou[i] == true && era.hyou[(i + 1) / 2] && i % 2 == 1 && i != 1)
      A[i]++;
  }
  REP(i, Q) {
    int l, r;
    cin >> l >> r;
    cout << A[r] - A[l - 1] << endl;
  }
}