#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  for (int i = 1; i < 10; i++) {
    if (111 * i >= N) {
      cout << 111 * i << endl;
      break;
    }
  }
}
