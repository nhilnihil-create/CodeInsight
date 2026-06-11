#include<bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    v[x-1] = i;
  }
  int res = n - 1;
  int l = 1;
  for (int i = n - 2; i >= 0; i--) {
    if (v[i] < v[i+1]) {
      l++;
      res = min(res, n - l);
    } else l = 1;
  }
  cout << res << endl;
}