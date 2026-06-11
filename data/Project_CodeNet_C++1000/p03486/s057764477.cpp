#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());  // sの並べ替えで最も小さい = 昇順
  sort(t.begin(), t.end(), greater<char>());  // tの並べ替えで最も大きい = 降順
  if (s < t) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}