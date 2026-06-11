#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  long a[n];
  for (int i=0; i<n; i++) cin>>a[i];

  sort(a, a + n);
  map<int, int> m;
  for (int i=0; i<n; i++) {
    ++m[a[i]];
  }

  int ans = 0;
  for (int i=32; i>=0; i--) {
    long b = pow(2, i);
    for (auto e: m) {
      long c = b - e.first;
      if (m.find(c) == m.end()) {
        continue;
      }
      if (c == e.first) {
        ans += e.second / 2;
        m[c] -= e.second / 2;
      } else if (e.second < m[c]) {
        ans += e.second;
        m[c] -= e.second;
        m[e.first] = 0;
      } else {
        ans += m[c];
        m[e.first] -= m[c];
        m[c] = 0;
      }
    }
  }
  cout<<ans<<endl;
}