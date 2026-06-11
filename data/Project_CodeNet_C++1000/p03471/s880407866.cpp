#include <bits/stdc++.h>
using namespace std;

int main() {

  int n ,m;

  cin >> n >> m;

  for (int i=0;i<=n;i++) {
    for (int j = 0;j<=n-i;j++) {
      int k = n-i-j;
      if (10000*i+5000*j+1000*k == m) {
        cout << i << ' ' << j << ' ' << k << endl; 
        return 0;
      }
    }
  }

  cout << -1 << ' ' << -1 << ' ' << -1 << endl;
  return 0;

}