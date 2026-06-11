#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, T;
  cin >> n >> T;
  vector<int> c(n), t(n);
  for(int i= 0; i < n; i++) cin >> c[i] >> t[i];
  int out = 10000;
  for (int i = 0; i < n; i++) {
    if (t[i] > T) continue;
    out = min(out, c[i]);
  }
  if (out == 10000) cout << "TLE" << endl;
  else cout << out << endl;
  return 0;
}