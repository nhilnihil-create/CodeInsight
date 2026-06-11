#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, k;
  cin >> n >> k;
  
  if (1 + (k - 1) * 2 <= n) cout << "YES\n";
  else cout << "NO\n";
}