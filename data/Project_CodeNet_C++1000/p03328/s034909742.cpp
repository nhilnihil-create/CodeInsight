#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int N = b - a;
  int sum = 0;
  int ans = 0;
  for (int i = 1; i <=  N; i++) {
    sum += i;
  }
  ans = sum - b;
  cout << ans << endl;
}