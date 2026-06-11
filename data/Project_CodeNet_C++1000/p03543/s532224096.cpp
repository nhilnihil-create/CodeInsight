#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N, a, b, c, d;
  cin >> N;
  a = N % 1000;
  b = N / 10 % 111;
  c = N % 1111;
  
  if (a == 0 || a == 111 || b == 0 || c == 0) {
    cout << "Yes" << endl;
  }
  
  else {
    cout << "No" << endl;
  }
}
  
  
  
  
  
    
  