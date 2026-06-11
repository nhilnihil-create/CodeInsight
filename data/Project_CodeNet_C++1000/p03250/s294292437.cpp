#include <bits/stdc++.h>
using namespace std;

int main() {
  int ar[3];
  cin >> ar[0] >> ar[1] >> ar[2];
  sort(ar, ar+3);
  int ans = ar[2] * 10 + ar[0] + ar[1];
  cout << ans << endl;
  return 0;
}