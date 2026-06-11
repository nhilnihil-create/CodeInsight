#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int M = N;
  int sum = 0;
  while (N) sum += N % 10, N /= 10;
  cout << ((M % sum) ? "No" : "Yes") << "\n";
}