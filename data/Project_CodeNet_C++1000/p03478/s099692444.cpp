#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b, ans = 0;
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) {
    int num = i/10000 + i%10000/1000 + i%1000/100 + i%100/10 + i%10;
    if (num >= a && num <= b)
      ans += i;
  }
  cout << ans << endl;
}