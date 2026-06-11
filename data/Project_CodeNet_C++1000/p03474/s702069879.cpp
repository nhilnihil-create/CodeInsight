#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  cin >> A >> B;
  
  string S;
  cin >> S;
  int countA = 0;
  int countab = 0;
  int countB = 0;
  
  for (int i = 0; i < A ; i++) {
    if (S.at(i) == '1' || S.at(i) == '2' || S.at(i) == '3' || S.at(i) == '4' || S.at(i) == '5' || S.at(i) == '6' || S.at(i) == '7' || S.at(i) == '8' || S.at(i) == '9' || S.at(i) == '0'){
      countA++;
    }
  }
  
  if (S.at(A) == '-'){
    countab++;
  }
  
  for (int i = A + 1; i < A + B + 1 ; i++) {
    if (S.at(i) == '1' || S.at(i) == '2' || S.at(i) == '3' || S.at(i) == '4' || S.at(i) == '5' || S.at(i) == '6' || S.at(i) == '7' || S.at(i) == '8' || S.at(i) == '9' || S.at(i) == '0'){
      countB++;
    }
  }
  
  if (countA == A && countab == 1 && countB == B){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
  

