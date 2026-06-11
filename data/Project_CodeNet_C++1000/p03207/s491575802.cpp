#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  sort(x.begin(), x.end());
  int z = 0;
  for (int i = 0; i < n-1; i++) {
    z += x[i];
  }
  cout << z+x[n-1]/2 << endl;
}