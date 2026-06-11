#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S; 
  string A = S.substr(0,2);
  string B = S.substr(2,2);
  
  int C = stoi(A);
  int D = stoi(B);
  
  int a = 0;
  int b = 0;
  
  if(0 <= C && C <= 99){
    if(1 <= D && D <=12){
      a = 1;
    }
  }
  if(1 <= C && C <= 12){
    if(0 <= D && D <=99 ){
      b = 1;
    }
  }
    
  if(a == 1 && b == 0){
    cout << "YYMM" << endl;
  }
  if(a == 0 && b == 1){
    cout << "MMYY" << endl;
  }
  if(a == 1 && b == 1){
    cout << "AMBIGUOUS" << endl;
  }
  if(a == 0 && b == 0){
    cout << "NA" << endl;
  }
}

