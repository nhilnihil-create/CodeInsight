#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a[5], k;
  for (int i = 0; i < 5; i++) {
    cin >> a[i];
  }
  cin >> k;
  if (a[4] - a[0] > k) {
    puts(":(");
  } else {
    puts("Yay!");
  }
  return 0;
}
