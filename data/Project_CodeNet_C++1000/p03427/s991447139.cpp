#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string n;
  cin >> n;
  bool nine = true;
  for (int i = 1; i < n.size(); ++i) {
    if (n[i] != '9') {
      nine = false;
    }
  }
  int ans = n[0] - '0' + 9 * (n.size() - 1);
  if (!nine) ans--;
  cout << ans << endl;
  return 0;
}