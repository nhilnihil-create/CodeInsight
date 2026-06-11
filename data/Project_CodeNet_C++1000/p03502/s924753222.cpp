#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, NN, a=0;
  cin >> N;
  NN = N;
  
  while (NN != 0) {
    int b;
    b=NN-NN/10*10;
    a += b;
    NN = NN/10;
  }
  
  int c;
  c = N%a;
  
  if (c==0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}