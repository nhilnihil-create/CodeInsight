#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
  string c1, c2;
  cin >> c1;
  cin >> c2;
  bool ans = true;
  rep(i, 3) {
    if (c1.at(i) != c2.at(2 - i)) ans = false;
  }
  if (ans == true) cout << "YES" << endl;
  else cout << "NO" << endl;
}