#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  vector<int> a(5);
  cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
  int k;
  cin >> k;
  bool ok = true;
  for (int i = 0; i < 5; i++) 
    for (int j = 0; j < 5; j++) 
      if (abs(a[i] - a[j]) > k)
        ok = false;
  cout << (ok ? "Yay!" : ":(");
  return 0;
}