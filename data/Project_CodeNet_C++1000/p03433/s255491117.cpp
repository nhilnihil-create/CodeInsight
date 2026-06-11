#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B;
  C = A%500;
  if(C <= B){
    cout << "Yes" << endl;
  }
  else if(C > B){
    cout << "No" << endl;
  }
}