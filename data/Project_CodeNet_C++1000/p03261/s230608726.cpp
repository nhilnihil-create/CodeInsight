#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> w_v(n);
  map<string, int> w_m;
  for (auto& x : w_v) {
    cin >> x;
    w_m[x]++;
  }
  string s, t;
  for (int i = 0; i < n - 1; i++) {
    s = w_v[i].back();
    t = w_v[i + 1].front();
    if (s != t || w_m[w_v[i]] > 1) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}