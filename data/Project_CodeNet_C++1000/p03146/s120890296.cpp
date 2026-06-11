#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;

int main() {
  
  int n;
  cin >> n;
  
  if (n < 3) cout << 4 << endl;
  else {
    int i = 1;
    while(1) {
      if (n == 4) break;
      if (n % 2 == 0) n /= 2;
      else n = 3 * n + 1;
      i++;
    }
    cout << i+3 << endl;
  }
}