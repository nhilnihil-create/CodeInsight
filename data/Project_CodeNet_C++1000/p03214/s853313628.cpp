#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
    sum += a.at(i);
  }
  
  int dif = 1e9, keep = 0;
  for (int i = 0; i < n; i++) {
    if (abs(sum - a.at(i) * n) < dif) {
      dif = abs(sum - a.at(i) * n);
      keep = i;
    }
  }
  
  cout << keep << '\n';
}