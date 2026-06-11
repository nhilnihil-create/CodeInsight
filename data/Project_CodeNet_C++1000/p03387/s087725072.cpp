#include <iostream>
using namespace std;

int main(){
  int A, B, C;
  cin >> A >> B >> C;
  int ans = 0;
  int MAX = max(A, max(B,C));
  int MIN = min(A, min(B,C));
  int MED = A+B+C-MAX-MIN;
  if((MAX%2) == ((A+B+C)%2)){
    cout <<  MAX-MED+(MED-MIN)/2;
  }else{
    cout << MAX-MED+(MED-MIN)/2+2;
  }
  return 0;
}