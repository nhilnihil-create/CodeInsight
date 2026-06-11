#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, total = 1;
  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    int a = total * 2;
    int b = total + K;
    if (a > b) {
      total = b;
    } else {
      total = a;
    }
  }
  cout << total << endl;
}