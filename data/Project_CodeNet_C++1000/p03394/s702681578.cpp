#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  if (n == 3) {
    cout << "2 5 63" << endl;
    return 0;
  }

  if (n & 1) {
    int cycle[] = {6, 2, 10, 3, 9, 4, 8, 12};
    for (int i = 0; i < n; ++i) {
      cout << cycle[i & 7] << ' ';
      cycle[i & 7] += 12;
    }
  } else {
    int cycle[] = {2, 10, 3, 9, 4, 8, 6, 12};
    for (int i = 0; i < n; ++i) {
      cout << cycle[i & 7] << ' ';
      cycle[i & 7] += 12;
    }
  }
  cout << endl;

  return 0;
}