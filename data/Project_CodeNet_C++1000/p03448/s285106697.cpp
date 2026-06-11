#include <bits/stdc++.h>
using namespace std;

int main() { 
  int a, b, c, n;
  cin >> a >> b >> c >> n;
  int count = 0;
  
  for (int i = 0; i <= a; i++) {
    for (int j = 0; j <= b; j++) {
      for (int k = 0; k <= c; k++) {
        int total = (500 * i) + (100 * j) + (50 * k);
        if (total == n) count++;
      }
    }
  }
  
  cout << count << endl;
}
