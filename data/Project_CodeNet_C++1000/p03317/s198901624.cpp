#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> as(n);
  int idx;
  rep(i, n) cin >> as[i];
  if ((n - k) % (k - 1) == 0) {
    cout << (n - k) / (k - 1) + 1 << endl;
  } else {
    cout << (n - k) / (k - 1) + 2 << endl;
  }
  return 0;
}
