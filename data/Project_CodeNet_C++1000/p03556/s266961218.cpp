#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  for (int i = 40000; i > 0; i--) {
    if (i * i <= N) {
      cout << i * i << endl;
      break;
    }
  }
}