#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string str;
  cin >> n >> str;
  int n1 = 0, n2 = 0;
  for (int i = 0; i < n; i++) {
    if (str.at(i) == 'R') {
      n1++;
    } else {
      n2++;
    }
  }
  if (n1 > n2) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
