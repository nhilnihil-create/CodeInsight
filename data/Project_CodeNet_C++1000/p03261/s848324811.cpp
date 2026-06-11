#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  vector<string> w(n);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> w.at(i);
  }
  bool flag = true;
  int ws;
  for (int i = 1; i < n; i++) {
    ws = w.at(i - 1).size();
    if (w.at(i - 1).at(ws - 1) != w.at(i).at(0)) {
      flag = false;
    }
    for (int j = 0; j < i; j++) {
      if (w.at(i) == w.at(j)) {
        flag = false;
      }
    }
  }
  if (flag) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
