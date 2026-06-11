#include <bits/stdc++.h>
using namespace std;

int power(int a, int n) {
  if (n == 1) return a;
  
  return power(a, n-1) * a;
}

void chmax(int& a, int b) {
  if (a < b) a = b;
}

int main() {
  int X;
  cin >> X;
  
  int ans = 1;
  
  for (int i = 2; i < 10; i++) {
    for (int j = 2; j < 33; j++) {
      int x = power(j, i);
      if (x <= X) {
        chmax(ans, x);
      } else {
        break;
      }
    }
  }
  
  cout << ans << endl;
}