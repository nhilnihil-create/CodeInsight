#include <bits/stdc++.h>
using namespace std;

int f (int &b, int &c) {
  int a;
  a = b + c;
  return a;
}

int main() {
  int A, B, C;
  long long int K;
  cin >> A >> B >> C >> K;
  
  if (K%2 == 0){
    A = A - B;
  }
  else {
    A = B - A;
  }
  
  
  cout << A << endl;
  
  
}
