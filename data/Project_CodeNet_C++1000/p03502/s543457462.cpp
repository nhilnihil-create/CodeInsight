#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  int f = 0;
  int x = 1;
  cin >> N;
  for (int i = 0; i < 8; i++) {
    f += N % (x * 10) / x;
    x *= 10;
  }
  if (N % f == 0) {cout << "Yes" << endl;}
  else {cout << "No" << endl;}
}