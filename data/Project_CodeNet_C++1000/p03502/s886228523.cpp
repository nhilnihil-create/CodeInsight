#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int sum = 0, a = 1, l;
  while (l != n) {
    a *= 10;
    l = n % a;
    sum += l / (a / 10);
  }
  
  if (n % sum == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}