#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  vector<int> x(4), y = {1, 1, 2, 2};
  for (int i = 0; i < 6; i++) {
    int a;
    cin >> a;
    x.at(a - 1)++;
  }
  
  sort(x.begin(), x.end());
  
  if (x == y) cout << "YES\n";
  else cout << "NO\n";
}