#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
  string s;
  cin >> s;
  rep(i, 7) {
    if (s.substr(0, i) + s.substr(s.size() - 7 + i) == "keyence") {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}