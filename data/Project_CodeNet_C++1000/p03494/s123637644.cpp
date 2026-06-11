#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int min;
  
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    
    int ope = 0;
    while (A % 2 == 0) {
      A /= 2;
      ope++;
    }

    if (i == 0) {
      min = ope;
    }
    
    if (ope < min) {
      min = ope;
    }
  }
  cout << min << endl;
}
