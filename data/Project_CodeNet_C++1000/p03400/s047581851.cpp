#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, D, X, A;
  cin >> N >> D >> X;
  while (cin >> A) {
    int tmp = 1, cnt = 1;
    while (tmp + A <= D) tmp += A, cnt++;
    X += cnt;
  }
  cout << X << "\n";
}