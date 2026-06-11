#include<bits/stdc++.h>
using namespace std;

int main(void){
  int A, B, C;
  cin >> A >> B >> C;
  int tmp = A * C;
  if(A <= B){
    if(B < tmp){
      tmp = B / A;
    }else{
      tmp = C;
    }
  }else{
    tmp = 0;
  }
  cout << tmp <<"\n";
  return 0;
}
