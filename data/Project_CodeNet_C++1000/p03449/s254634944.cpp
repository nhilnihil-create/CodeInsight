#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  vector<int> b(n);
  for(int i=0; i<n; i++) cin >> b[i];
  
  int ans = 0;
  int c = 0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(j==i) c += b[j];
      if(j<=i) c += a[j];
      else c += b[j];
    }
    if(ans<c) ans = c;
    c = 0;
  }
  
  cout << ans << endl;
  return 0;
}