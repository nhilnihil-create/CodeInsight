#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }
  int m;
  cin >> m;
  vector<int> t(m);
  for (int i = 0; i < m; i++) {
    cin >> t[i];
  }
  sort(d.begin(), d.end());
  sort(t.begin(), t.end());
  int j = 0;
  for (int i = 0; i < m; i++) {
    while (d[j] < t[i] && j < n) j++;
    if (d[j] != t[i]) {
      cout << "NO" << endl;
      return 0;
    } else {
      j++;
    }
  }
  cout << "YES" << endl;

  return 0;
}