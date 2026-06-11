#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  
  int x1, x2, x4, x5, tmp, count = 0;
  for (int i=A; i<=B; i++) {
    tmp = i;
    x5 = tmp % 10; tmp /= 10;
    x4 = tmp % 10; tmp /= 100;
    x2 = tmp % 10; tmp /= 10;
    x1 = tmp % 10;
    
    if ((x1 == x5) && (x2 == x4)) {
      count++;
    }
  }
  
  cout << count << endl;
}