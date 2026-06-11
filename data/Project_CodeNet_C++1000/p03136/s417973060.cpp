#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> li(n);
  int m = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> li.at(i);
    m = max(m, li.at(i));
    sum += li.at(i);
  }
  if (m < sum-m) cout << "Yes" << endl;
  else cout << "No" << endl; 
}