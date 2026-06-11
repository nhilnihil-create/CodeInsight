#include <bits/stdc++.h>
using namespace std;
int func (int n) {
  int sum=0;
  while(n > 0) {
    sum += n%10;
    n /= 10;
  }
  return sum;
}
int main() {
  int n;
  cin >> n;
  int min=10000000;
  for (int i=1; i < n; i++) {
      int d = func(i) + func(n-i);
      if (d < min) min = d;
  }
  cout << min << endl;
}