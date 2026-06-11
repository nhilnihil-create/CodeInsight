#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N + 1; i++) {
    if (i * i > N) {
      cout << (i - 1) * (i - 1) << endl;
      break;
    }
    else if (i * i == N) {
      cout << i * i << endl;
      break;
    }
  }
}