#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v.at(i);
  }
  sort(v.begin(), v.end());
  int s = 0;
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (s + v.at(i) <= x) {
      s += v.at(i);
      c++;
    }
    else break;
  }
  if (s < x && c == n) cout << n - 1 << endl;
  else cout << c << endl;
}