#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  
  int count = 0;
  for (int i = 1; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        int a = 10001 * i + 1010 * j + 100 * k;
        if (A <= a && a <= B) {
          count += 1;
        }
      }
    }
  }
  cout << count << endl;
}
       