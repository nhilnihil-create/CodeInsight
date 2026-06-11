#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int x = 0;
  for (int i = 0; i < n; i++) {
    x += a[i];
  }
  if (a[n-1] >= x-a[n-1]) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
}