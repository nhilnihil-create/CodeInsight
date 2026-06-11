#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int x;
  cin >> x;
  int mx = 0;
  for (int i = 1; i <= 100; i++) {
    for (int j = 2; j <= 10; j++) {
      int t = pow(i, j);
      if (t > x) break; 
      mx = max(mx, t);
    }
  }
  cout << mx << endl;
  return 0;
}