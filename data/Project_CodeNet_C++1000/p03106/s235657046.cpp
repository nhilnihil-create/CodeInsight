#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep2(i,n) for (int i = 1; i <= (n); i++)
using namespace std;

int main() {
  int a, b, k;
  cin >> a >> b >> k;

  int count = 0;

  for (int i = 100; i >= 1; i--) {
    if (a % i == 0 && b % i == 0) {
      count++;
      if (count == k) {
        cout << i << endl;
        break;
      }
    }
  }
  
  return 0;
}
