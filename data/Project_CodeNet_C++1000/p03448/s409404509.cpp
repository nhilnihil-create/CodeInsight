#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, x;
  int count = 0;
  cin >> a >> b >> c >> x;
  for (int i = 0; 500 * i <= x; i++) {
    for (int j = 0; 100 * j <= x - 500 * i; j++) {
      if (a >= i && b >= j && c >= (x - 500 * i - 100 * j) / 50){
        count++;
      }
    }
  }
cout << count <<endl;

  return 0;
}
