#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int x = 0, y = 1;
  for (int i = 0; i < 9; i++) {
    x = x + N / y % 10;
    y = y * 10;
  }
  if (N % x == 0) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
