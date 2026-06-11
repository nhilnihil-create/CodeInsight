#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int64_t a = 2, b = 1, c = 1;
  cin >> N;
  for (int i= 1; i < N; i++) {
    b = b + a;
    a = c;
    c = b;
  }
  cout << b << endl;
}