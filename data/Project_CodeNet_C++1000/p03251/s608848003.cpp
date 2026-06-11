#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<int> a(n);
  vector<int> b(m);
  for(int i=0; i<n; i++) cin >> a[i];
  sort(a.rbegin(), a.rend());
  for(int i=0; i<m; i++) cin >> b[i];
  sort(b.begin(), b.end());
  
  if(a[0] >= b[0]) {
    cout << "War" << endl;
    return 0;
  }
  
  else {
    for(int i=a[0]+1; i<=b[0]; i++) {
      if(x<i && i<=y) {
        cout << "No War" << endl;
        return 0;
      }
    }
    cout << "War" << endl;
    return 0;
  }
}