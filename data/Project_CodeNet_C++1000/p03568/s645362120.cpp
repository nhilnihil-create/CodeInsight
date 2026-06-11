#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, i = 1;
  cin >> N;
  while (cin >> A) i *= (A % 2) ? 1 : 2;
  cout << pow(3, N) - i << "\n";
}