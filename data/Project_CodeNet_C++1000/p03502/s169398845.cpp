#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int total = N % 10;
  int base = 10;
  int x = 1;
  while (N / base != 0) { 
    x += 1;
    base *= 10;
  }
  base = 10; 
  for (int i = 1; i < x; i++) {
    total = total + (N % (base * 10) - N % base) / base;
    base *= 10;
  }
  if (N % total == 0) {
    cout << "Yes" << endl;
  }
  else if (N % total != 0) {
    cout << "No" << endl;
  }
}