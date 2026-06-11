#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B, x, count = 0;
  cin >> A >> B;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        x = i * 10001 + j * 1010 + k * 100;
        if (x >= A && x <= B)
          count++;
      }
    }
  }
  cout << count << endl;
}