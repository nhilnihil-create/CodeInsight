#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
bool erato[(int)1e5 + 20];
int main() {
  ll Q;
  cin >> Q;
  REP(i, (int)1e5 + 20) erato[i] = true;
  erato[0] = false;
  for (int i = 2; i <= (int)(1e5) / i; i++) {
    if (erato[i] != true) {
      continue;
    }
    for (int j = 2; j * i <= (int)(1e5); j++) {
      erato[i * j] = false;
    }
  }
  for (int i = (int)1e5; i > 1; i--) {
    if (i % 2 == 0) {
      erato[i] = false;
      continue;
    }
    if (erato[i] && erato[(i + 1) / 2]) {
      erato[i] = true;
    } else {
      erato[i] = false;
    }
  }
  erato[0] = false, erato[1] = false, erato[2] = false;
  vector<int> wa(1e5 + 20);
  wa[0] = 0;
  for (int i = 1; i <= 1e5 + 1; i++) {
    wa[i] = wa[i - 1] + erato[i];
  }
  REP(i, Q) {
    int l, r;
    cin >> l >> r;
    cout << wa[r] - wa[l - 1] << endl;
  }
}