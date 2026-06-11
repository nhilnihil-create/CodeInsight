#include <bits/stdc++.h>
using namespace std;

int main () {
  int A, B, C;
  int K;
  cin >> A >> B >> C;
  cin >> K;
  
  int counter = 0;
  int tmp = 0;
  for (int i = 0; i < A+1; i++) {
    for (int j = 0; j < B+1; j++) {
      for (int k = 0; k < C+1; k++) {
        tmp = 500 * i + 100 * j + 50 * k;
        if (tmp == K) {
          counter++;
        }
      }
    }
  }
  
  cout << counter << endl;
  
}
