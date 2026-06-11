#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    b[i]--;
  }

  stack<int> s;
  bool ok = true;
  for (int i = 0; i < n; i++) {
    for (int j = (int)b.size() - 1; j >= 0; j--) {
      if (b[j] == j) {
        s.push(j + 1);
        b.erase(b.begin() + j);
        break;
      }
      if (j == 0) {
        ok = false;
        break;
      }
    }

    if (!ok) {
      break;
    }
  }

  if (ok) {
    while (!s.empty()) {
      cout << s.top() << endl;
      s.pop();
    }
  } else {
    puts("-1");
  }

  return 0;
}
