#include <bits/stdc++.h>
using namespace std;

int main() {
  set<string> se;
  int N;
  cin >> N;
  bool ok = true;
  string prev; cin >> prev; se.insert(prev);
  for (int i = 1; i < N; ++i) {
    string cur;
    cin >> cur;
    if (prev.back() != cur[0]) ok = false;
    if (se.count(cur)) ok = false;
    se.insert(cur);
    prev = cur;
  }
  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}