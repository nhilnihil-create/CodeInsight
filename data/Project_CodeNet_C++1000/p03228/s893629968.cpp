#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
  int A,B,K;
  cin >> A >> B >> K;

  int turn = 0;

  for(int i=0;i<K;i++){
    if(turn == 0){
      if(A % 2 == 1)
        A--;;
      B += A / 2;
      A /= 2;
      turn = 1;
    }
    else{
      if(B % 2 == 1)
        B--;
        A += B / 2;
        B /= 2;
      turn = 0;
    }
  }

  cout << A << " " << B << endl;

  return 0;
}
