#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int r,d,x;
  cin >> r >> d >> x;
  int cnt = 0;
  while (cnt < 10) {
    cnt++;
    x = r * x - d;
    cout << x << endl;
  }
  return 0;
}