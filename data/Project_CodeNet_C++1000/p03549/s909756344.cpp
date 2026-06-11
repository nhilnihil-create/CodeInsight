#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  cout << (m * 1900 + (n - m) * 100) * pow(2, m) << '\n';
  return 0;
}