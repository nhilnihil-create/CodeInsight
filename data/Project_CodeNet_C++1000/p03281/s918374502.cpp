#include <bits/stdc++.h>
using namespace std;

bool check(int n) {
  int count=0;
  if (n % 2 == 0) return false;
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) count++;
  }
  if (count == 8) return true;
  else
    return false;
}

int main() {
  int n, out=0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    if (check(i) == true) out++;
  }
  cout << out << endl;
  return 0;
}