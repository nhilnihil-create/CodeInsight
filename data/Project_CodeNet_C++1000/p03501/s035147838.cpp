#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  int X = N * A;
  
  if (X > B) {
    cout << B << endl;
  }
  else if (X <= B){
    cout << X << endl;
  }
  
     
}