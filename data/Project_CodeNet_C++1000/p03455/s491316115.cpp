#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B;
  C = A*B;
  if(C%2 == 0){
    cout << "Even" << endl;
  }
  else if(C%2 == 1){
    cout << "Odd" << endl;
  }
}