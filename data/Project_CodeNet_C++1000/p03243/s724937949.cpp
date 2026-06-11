#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  while (true) {
    int a = N / 100;
    int b = (N/10) % 10;
    int c = N % 10;
    
    if (a == b && b == c) {
      cout << 100 * a + 10 * b + c << endl;
      return 0;
    }
    N++;
  }
  
  
  
  
  
  
}