#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  
  int a, b, c = 0, d = 100001;
  vector<int> v(n);
  for(int i=0; i<m; i++) {
    cin >> a >> b;
    c = max(c, a);
    d = min(d, b);
  } 
  
  if(d-c>=0) cout << d-c+1 << endl;
  else cout << 0 << endl;
  return 0;
}