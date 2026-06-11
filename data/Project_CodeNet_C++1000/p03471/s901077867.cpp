#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  
  bool exist = false;
  int a, b, c;
  for(int i=0; i<=n; i++) {
    for(int j=0; j<=n; j++) {
      if(1000*i+5000*j+10000*(n-(i+j))==m && n-(i+j)>=0) {
        exist = true;
        a=n-(i+j), b=j, c=i;
      }
    }
    if(exist) break;
  }
  
  if(exist) cout << a << " " << b << " " << c;
  else cout << "-1 -1 -1" << endl;
  return 0;
}