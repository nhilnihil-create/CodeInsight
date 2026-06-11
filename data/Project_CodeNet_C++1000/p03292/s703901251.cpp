#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> a(3);
  for (int i = 0; i < 3; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int x = a[0]-a[1];
  int y = a[1]-a[2];
  cout << abs(x+y) << endl;
}