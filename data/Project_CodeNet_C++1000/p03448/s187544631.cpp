#include <bits/stdc++.h>
using namespace std;


int main() {
  int A;
  cin >> A;
  int B;
  cin >> B;
  int C;
  cin >> C;
  int X;
  cin >> X;
  
  int count = 0;
  for (int a = 0; a <= A; a++) {
    for (int b = 0; b <= B; b++) {
      for (int c = 0; c <= C; c++) {
        int total = a*500 + b*100 + c*50;
        if (X == total) count++;
      }
    }
  }
  cout << count << endl;
}  
