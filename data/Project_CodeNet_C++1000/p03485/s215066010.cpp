#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, Z;
  double mean;
  cin >> A >> B;
  mean = (double)(A + B) / 2;
  Z = (A + B) / 2;
  mean = mean - Z;
  if(mean >= 0.5){
    cout << Z + 1 << endl;
  }
  else{
    cout << Z << endl;
  }
  return 0;
}
