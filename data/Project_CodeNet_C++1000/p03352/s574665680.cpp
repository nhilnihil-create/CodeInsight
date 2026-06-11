#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  vector<int> a = {1};
  for (int b = 2; b <= 32; b++) {
    int k = b;
    while (k <= 1000) {
      k *= b;
      a.push_back(k);
    }
  }
  sort(a.begin(), a.end());
  int k = upper_bound(a.begin(), a.end(), x) - a.begin();
  cout << a[k-1] << endl;
  return 0;
}