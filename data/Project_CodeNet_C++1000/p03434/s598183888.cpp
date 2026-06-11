#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec.at(i);
  }
  int m,f = 0;
  long long a,b = 0;
  for (int i = 0; i < n; i++) {
    m = 0;
    for (int j = 0; j < n; j++) {
      if (vec.at(j) > m) {
        m = vec.at(j);
        f = j;
      }
    }
    vec.at(f) = 0;
    if (i % 2 == 0) {
      a += m;
    } else {
      b += m;
    }
  }
  int ans = abs(a - b);
  cout << ans << endl;
}