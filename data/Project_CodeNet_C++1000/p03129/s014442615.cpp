#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  if (k <= n - n / 2) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
  return 0;
}