#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
  cin >> n;
  int res = 1, sum = 1;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    res *= 2 - (a & 1);
    sum *= 3;
  }
  cout << sum - res << endl;
  return 0;
}
