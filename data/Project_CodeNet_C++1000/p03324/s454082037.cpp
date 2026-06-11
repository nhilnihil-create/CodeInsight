#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
  ll D, N;
  cin >> D >> N;

  if (D == 0) {
    if (N == 100) {
      cout << N + 1 << endl;
    } else {
      cout << N << endl;
    }
    return 0;
  }

  if (D == 1) {
    if (N == 100) {
      cout << N * 100 + 100 << endl;
    } else {
      cout << N * 100 << endl;
    }
    return 0;
  }

  if (N == 100) {
    cout << N * 10000 + 10000 << endl;
  } else {
    cout << N * 10000 << endl;
  }
  
  return 0;
}