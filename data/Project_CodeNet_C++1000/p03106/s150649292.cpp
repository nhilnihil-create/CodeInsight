#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int A, B, K;
  cin >> A >> B >> K;
  int ans = gcd(A, B);
  int c = 0;
  for (int i = 1; i < A * B; i++) {
    if (ans % i == 0) {
      c++;
    }
    if (c == K) {
      ans /= i;
      break;
    }
  }  
  cout << ans << endl;
}