#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  int mx = min(a, b);
  int mn = max(0, a + b - n);
  cout << mx << " " << mn << endl;
}