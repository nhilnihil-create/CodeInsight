#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int ans = n * (180 - 360 / double(n));
  cout << ans << endl;
}