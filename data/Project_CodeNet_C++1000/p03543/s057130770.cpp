#include <bits/stdc++.h>
using namespace std;
int main() {
  string n;
  int cnt = 0;
  cin >> n;
  for (int i = 0; i < 3; i++) {
    if (n[i] == n[i + 1]) cnt += 1;
  }
  if (cnt >= 2 && n[1] == n[2]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}