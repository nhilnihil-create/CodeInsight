#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
  int t, a, b;
  cin >> t >> a >> b;
  int d = min(t * a, b);
  cout << d << endl;
}