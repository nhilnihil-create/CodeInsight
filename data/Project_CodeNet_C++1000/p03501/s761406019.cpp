#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,B;
  
  cin >> N >> A >> B;
  
  int a = A * N;
    
  if (a >= B) {
    cout << B << endl;
  }
  else if (a < B) {
    cout << a << endl;
  }
}