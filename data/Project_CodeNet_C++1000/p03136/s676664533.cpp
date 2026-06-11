#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> l(n);
  for (int i = 0; i < n; i++) {
    cin >> l.at(i);
  }
  sort(l.begin(), l.end());
  int sum = 0;
  for (int i = 0; i < n - 1; i++) {
    sum += l.at(i);
  }
  if (sum > l.at(n - 1)) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
