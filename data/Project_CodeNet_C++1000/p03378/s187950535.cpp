#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,m,x;
  cin >> n >> m >> x;
  vector<bool> list(n+1);
  int t;
  for(int i=0; i<m; i++) {
    cin >> t;
    list.at(t) = true;
  }
  int a=0,b=0;
  for(int i=x; i<=n; i++) {
    if(list.at(i)) {
      a += 1;
    }
  }
  for(int i=x; i>=0; i--) {
    if(list.at(i)) {
      b += 1;
    }
  }
  cout << min(a,b) << endl;
}