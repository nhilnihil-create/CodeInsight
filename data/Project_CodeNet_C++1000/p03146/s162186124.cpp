#include <bits/stdc++.h>
using namespace std;

int main() {
  int s;
  cin >> s;
  vector<int> a(1000000);
  a.at(0) = s;
  for (int i = 1; i < 500; ++i) {
    if (a.at(i - 1) % 2 == 0) {
      a.at(i) = a.at(i - 1) / 2;
    }
    else {
      a.at(i) = 3 * a.at(i - 1) + 1;
    }
  }

  for (int i = 0; i < 500; ++i) {
    for (int j = i + 1; j < 500; ++j) {
      if (a.at(i) == a.at(j)) {
        cout << j + 1 << endl;
        return 0;
      }

    }
  }
  return 0;
}

