#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  
  int ans = 0;
  for (int i = A; i <= B; i++) {
    int x = 0;
    for (int j = i; j > 0; j /= 10) {
      x = 10 * x + j % 10;
    }
    
    if (x == i) {
      ans++;
    }
  }
  
  cout << ans << endl;
}
